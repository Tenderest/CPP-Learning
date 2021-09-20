#include <iostream>
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>

/**
 * 条件变量 condition_variable, wait, notify_one, notify_all
 *                  ^
 *                  |
 *                一个类
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
            std::condition_variable _condition_var;
        public:
            void saveCommand() // 把命令加入队列
            {
                for(int i = 0; i < 50; ++i)
                {
                    std::cout << "save command" << i << std::endl; // 为了确保锁定执行的顺序在后面
                    std::unique_lock<std::mutex> _unique_L(_mutex);
                    _command.push_back(i);
                    _condition_var.notify_one(); // 尝试把 wait 的线程唤醒
                }
            }

            void pickCommand()
            {
                while (true)
                {
                    std::unique_lock<std::mutex> _unique_L(_mutex);
                    // 如果第二参数函数（条件） 返回的是 false 那么 wait() 会解锁互斥量，并阻塞（睡眠）
                    // 如果条件返回的是 true 则不阻塞（此时是有锁，已经 lock），会继续执行后面的代码
                    // 直到某个时刻在其他地方调用了 notify_one() 函数
                    // 如果没有第二参数（条件）则是等待，睡眠，直到使用 notify_one() 唤醒，然后继续执行后面的代码
                    //（以下是有第二参数函数（条件）的情况）
                    // 如果被唤醒了则 相当于重新执行一遍 wait() 函数的流程，加锁，判断条件，阻塞，被唤醒
                    //   a. 不断尝试重新获取互斥量锁，如果获取不到则阻塞
                    //   b. 同上 (如果第二参数函数（条件） 返回的是 false ...)
                    _condition_var.wait(_unique_L,
                                        [this]() -> bool {
                                            if (!this->_command.empty())
                                            {
                                                return true;
                                            }
                                            return false;
                                        });
                    // 如果在着则是拥有了互斥锁，一定是已经 lock 了的
                    // 也有数据
                    std::cout << "---> pick command: " <<  _command.front() << std::endl;
                    _command.pop_front();
                    _unique_L.unlock();
                } // end while




                /***********************************/
                // for(int i = 0; i < 50; ++i)
                // {
                //     if (!_command.empty())
                //     {
                //         std::cout << "---> pick command: " <<  _command.front() << std::endl;
                //         std::unique_lock<std::mutex> _unique_L(_mutex);
                //         _command.pop_front();
                //     }
                //     else
                //     {
                //         std::cout << "list is empty!" << std::endl;
                //     }
                // }
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
