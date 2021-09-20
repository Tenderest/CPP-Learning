#include <iostream>
#include <thread>
#include <list>
#include <mutex>

/**
 * 多个线程，数据共享问题
 * 使用互斥量解决
 * lock() & unlock() 成对出现
 * std::lock_guard 类模板 直接取代 lock() & unlock() 之后便不使用 lock() & unlock()
 * 注意死锁问题 一般解决方案：加锁 lock 的顺序一致
 * std::lock<typename _L1, typename _L2, typename... _L3>() 函数模板 一次锁住两个（必须是两个）  或者两个以上的互斥量
 * 如果有一个没锁住，则会释放掉前面锁住的，所以必须同时锁成功
 * 需要与 unlock() 配合
 * template<typename _L1, typename _L2, typename... _L3>
     void
     lock(_L1& __l1, _L2& __l2, _L3&... __l3)
     {
       while (true)
         {
           using __try_locker = __try_lock_impl<0, sizeof...(_L3) != 0>;
           unique_lock<_L1> __first(__l1);
           int __idx;
           auto __locks = std::tie(__l2, __l3...);
           __try_locker::__do_try_lock(__locks, __idx);
           if (__idx == -1)
             {
               __first.release();
               return;
             }
         }
     }
 */

namespace ff {
    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }

    class Command {
        private:
            std::list<int> _command;
            std::mutex _mutex;
        public:
            void saveCommand()
            {
                for(int i = 0; i < 50; ++i)
                {
                    std::cout << "save command" << i << std::endl;
                    /*
                      std::lock(_mutex1, _mutex2);
                      std::lock_guard<std::mutex> _L1_guard(_mutex1, std::adopt_lock);
                      std::lock_guard<std::mutex> _L2_guard(_mutex2, std::adopt_lock);
                    */
                    _mutex.lock();
                    _command.push_back(i);
                    _mutex.unlock(); // 当没有 unlock 的时候，其他线程没法加锁！！
                }
            }

            void pickCommand()
            {
                for(int i = 0; i < 50; ++i)
                {
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
