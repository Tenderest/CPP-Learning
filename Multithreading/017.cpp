#include <iostream>
#include <thread>
#include <list>
#include <mutex>
#include <windows.h>

/**
 * 一、 Windows 临界区
 *   定义一个宏 __WINDOWS_SECTION_ ，其中包含的代码就是临界区的代码
 * 二、 多次进入临界区试验
 *   在“同一个线程”（不同线程就是卡住等待）中，Windows 中的“相同临界区变量”（类比于不同的 mutex，不同的锁当然无法锁住）代表的临界区可以多次进入
 *      EnterCriticalSection(&_winsec); // 进入临界区
 *      EnterCriticalSection(&_winsec); // 进入临界区
 *      EnterCriticalSection(&_winsec); // 进入临界区
 *      _command.push_back(i);
 *      LeaveCriticalSection(&_winsec); // 离开临界区
 *      LeaveCriticalSection(&_winsec); // 离开临界区
 *      LeaveCriticalSection(&_winsec); // 离开临界区
 *   但需要注意的是，进入几次需要离开几次，即 x 进 x 出，如 3 进 3 出
 *   !! 同一个 mutex 不能 lock 两次
 * 三、 自动析构技术
 *   利用类的 构造函数 和 析构函数来实现，类中需要保存一个临界区对象
 *   这种类叫 RAII 类（Resource Acquisition is initialization） “资源获取即初始化”
 *   容器、智能指针、Win_section_guard 属于此类
 * 四、 递归的独占互斥量 recursive_mutex
 *   lock() 调用超过一次就会报异常
 *   情景：在一个（A）函数中 lock() 了一次，然后需要用到别的（B）函数，在别的（B）函数中又进行了 lock() 操作，因为这个操作不可不进行
 *   （B）函数是之前写好的代码，此次调用的代码类似于
 *   void B() {
 *       lock();
 *       // do something..
 *   }
 *
 *   void A() {
 *       lock();
 *       // do something..
 *       B();
 *       C();
 *       // do something..
 *   }
 *   std::mutex 独占式互斥量，自己 lock 而别人无法 lock
 *   std::recursive_mutex 递归的独占互斥量，允许同一个互斥量被多次 lock
 *   可以解决多次锁的问题，但效率比 mutex 低一些，递归的次数也有限制
 */

#define __WINDOWS_SECTION_
namespace ff {
    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }

    class Win_section_guard {
    private:
        CRITICAL_SECTION *_sec;
    public:
        Win_section_guard(CRITICAL_SECTION *sec) : _sec(sec)
        {
            EnterCriticalSection(this->_sec);
        }
        ~Win_section_guard()
        {
            LeaveCriticalSection(this->_sec);
        }
    };

    class Command {
    private:
        std::list<int> _command;
        std::mutex _mutex;
        std::recursive_mutex _recursiveMutex;
#ifdef __WINDOWS_SECTION_
        CRITICAL_SECTION _winsec; // Windows 中的临界区，非常类似于 C++11 中的 mutex
#endif /* __WINDOWS_SECTION_ */
    public:
        Command()
        {
#ifdef __WINDOWS_SECTION_
            InitializeCriticalSection(&_winsec); // 使用临界区之前必须先初始化
#endif /* __WINDOWS_SECTION_ */
        }
        void saveCommand()
        {
            for(int i = 0; i < 50; ++i)
            {
                std::cout << "插入一个 command" << i << std::endl;
#ifdef __WINDOWS_SECTION_
                EnterCriticalSection(&_winsec); // 进入临界区
                EnterCriticalSection(&_winsec); // 进入临界区
                EnterCriticalSection(&_winsec); // 进入临界区
                _command.push_back(i);
                LeaveCriticalSection(&_winsec); // 离开临界区
                LeaveCriticalSection(&_winsec); // 离开临界区
                LeaveCriticalSection(&_winsec); // 离开临界区
#else
                _mutex.lock();
                _command.push_back(i);
                _mutex.unlock(); // 当没有 unlock 的时候，其他线程没法加锁！！
#endif /* __WINDOWS_SECTION_ */
            }
        }

        void pickCommand()
        {
            for(int i = 0; i < 50; ++i)
            {
#ifdef __WINDOWS_SECTION_
                EnterCriticalSection(&_winsec);
                if (!_command.empty())
                {
                    // _mutex.lock();
                    std::cout << _command.front() << std::endl;
                    _command.pop_front();
                    // _mutex.unlock(); // 当没有 unlock 的时候，其他线程没法加锁！！
                }
                else
                {
                    std::cout << "list is empty!" << std::endl;
                }
                LeaveCriticalSection(&_winsec);
#else
                std::lock_guard<std::mutex> _lock_guard(_mutex); // 构造时 lock 析构时 unlock
                if (!_command.empty())
                {
                    // _mutex.lock();
                    std::cout << _command.front() << std::endl;
                    _command.pop_front();
                    // _mutex.unlock(); // 当没有 unlock 的时候，其他线程没法加锁！！
                }
                else
                {
                    std::cout << "list is empty!" << std::endl;
                }
#endif /* __WINDOWS_SECTION_ */
            }
        }

    };
}

int main(void)
{
    std::cout << "Main thread start" << std::endl;
    std::cout << "主线程 id = " << std::this_thread::get_id() << std::endl;
    ff::Command command;
    std::thread save_command(&ff::Command::saveCommand, &command);
    std::thread pick_command(&ff::Command::pickCommand, &command);
    // if (save_command.joinable() && pick_command.joinable()) {
    //     save_command.join(); // 阻塞主线程
    //     pick_command.join();
    // }
    // list 好像线程安全了
    save_command.join();
    pick_command.join();
    std::cout << "Main thread stop" << std::endl;
    return 0;
}
