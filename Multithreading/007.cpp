#include <iostream>
#include <thread>
#include <list>
#include <mutex>

/**
 * 多个线程，数据共享问题
 * 使用 unique_lock 类模板
 * 第二参数，lock_guard 同样适用
 * std::adopt_lock 标记 表示已经被 lock 了，无需在构造函数中 lock 了
 * std::try_to_lock 标记 尝试 lock 如果没有成功则返回，不阻塞 不等待其他进程
 * std::defer_lock 标记 表示初始化一个没有加锁的 mutex 以方便调用 unique_lock 的一些成员函数
 * 
 * unique_lock 类模板 release() 释放管理的 mutex 归还指针，返回值是指针 unique_lock & mutex 将没有关系
 * unique_lock 的所有权传递，类似智能指针中的 unique_ptr , unique_lock 的做法是添加右值引用的的 copy 函数，调用 move 函数
 *              来传递所有权，拷贝构造函数（copy constructor）和拷贝赋值函数（copy assignment constructor） 设置成 delete
 *              C++ 不会自动生成，相当于删除了这个操作（没有C++提供的函数，也没有自己提供）
 *              使用时调用 std::unique_lock<std::mutex> _unique_L_1(_mutex); // 移动后锁的状态没有变化 lock 还是 lock
 *                        std::unique_lock<std::mutex> _unique_L_2(std::move(_unique_L_1));
 * 
 * std::unique_lock<std::mutex> ret_unique_lock() {
 *   std::unique_lock<std::mutex> _tmp_lock(_mutex);
 *   return _tmp_lock; // 这里会调用 移动构造函数 返回局部对象，导致系统生成临时的 unique_lock 对象，并调用移动构造函数
 * }
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
                    // std::cout << "save command" << i << std::endl;
                    // std::lock_guard<std::mutex> _lock_guard(_mutex); // 构造时 lock 析构时 unlock
                    // std::unique_lock<std::mutex> _lock_guard(_mutex); // 构造时 lock 析构时 unlock
                    std::unique_lock<std::mutex> _lock_guard(_mutex, std::try_to_lock);
                    if (_lock_guard.owns_lock())
                    {
                        std::cout << "save command" << i << std::endl;
                        _command.push_back(i);
                    }
                    else
                    {
                        std::cout << "saveCommand 没有拿到锁" << i << std::endl;
                    }
                }
            }

            void pickCommand()
            {
                for(int i = 0; i < 50; ++i)
                {
                    // std::lock_guard<std::mutex> _lock_guard(_mutex); // 构造时 lock 析构时 unlock
                    std::unique_lock<std::mutex> _lock_guard(_mutex); // 构造时 lock 析构时 unlock
                    std::chrono::milliseconds _sleep_milliseconds(10000);
                    std::this_thread::sleep_for(_sleep_milliseconds); // sleep 10s

                    if (!_command.empty())
                    {
                        std::cout << _command.front() << std::endl;
                        _command.pop_front();
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

    // list 好像线程安全了
    save_command.join();
    pick_command.join();
    std::cout << "Main thread stop" << std::endl;
    return 0;
}
