#include <iostream>
#include <thread>
#include <list>

/**
 * 多个线程，数据共享问题
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
        public:
            void saveCommand()
            {
                for(int i = 0; i < 50; ++i)
                {
                    std::cout << "save command" << i << std::endl;
                    _command.push_back(i);
                }
            }

            void pickCommand()
            {
                for(int i = 0; i < 50; ++i)
                {
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
