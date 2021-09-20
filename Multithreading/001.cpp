#include <iostream>
#include <thread>

/**
 * 使用 detach 时的问题：
 * 1. 如果 可调用函数，或者 可调用对象 中使用了 引用类型（&），那么极有可能会出错
 *      原因：主线程执行完退出，变量的内存栈被销毁，引发内存泄漏
 */

namespace ff {
    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }

    void my_thread_001() {
        std::cout << "-- my thread start" << std::endl;
        std::cout << "-- " << std::thread::id() << std::endl;
        print(1, 2, "abc");
        std::cout << "-- my thread stop" << std::endl;
    }

    void my_thread_002() {
        for (int i = 0; i < 300; i++)
        {
            std::cout << "-- my thread 002 for " << i << std::endl;
        }
    }
}

int main(void)
{
    std::cout << "Main thread start" << std::endl;
    // try {
    //     std::thread t1(ff::my_thread_001);
    //     if (t1.joinable()) {
    //         t1.join(); // 阻塞主线程
    //     }
    // }
    // catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }
    std::thread t1(ff::my_thread_001);
    if (t1.joinable()) {
        t1.join(); // 阻塞主线程
    }

    std::thread t2(ff::my_thread_002);
    if (t2.joinable()) {
        t2.detach(); // 分离线程，之后无法 join
        // t2.join();
    }
    std::cout << "Main thread stop" << std::endl;
    return 0;
}
