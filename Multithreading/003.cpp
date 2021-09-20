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

    auto lambda_thread = [](){
        std::cout << "-- lambda thread strat" << std::endl;
        std::cout << "-- " << std::thread::id() << std::endl;
        print(4, 5, "ghi");
        std::cout << "-- lambda thread stop" << std::endl;
    };
}

int main(void)
{
    std::cout << "Main thread start" << std::endl;
    std::thread t1(ff::lambda_thread); // 相当于传入了一个函数
    if (t1.joinable()) {
        t1.join(); // 阻塞主线程
    }
    std::cout << "Main thread stop" << std::endl;
    return 0;
}
