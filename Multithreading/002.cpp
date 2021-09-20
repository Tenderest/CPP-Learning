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

    class My_thread_003 {
        public:
        void operator() () {
            std::cout << "-- my thread(class operator() ) start" << std::endl;
            std::cout << "-- " << std::thread::id() << std::endl;
            std::cout << "-- this " << this << std::endl;
            print(3, 4, "def");
            std::cout << "-- my thread(class operator() ) stop" << std::endl;
        }
        My_thread_003() {std::cout << "-- 构造函数 Construct " << this << std::endl;}
        My_thread_003(const My_thread_003& copy) {std::cout << "-- 拷贝构造函数 Copy construct " << this << std::endl;}
        ~My_thread_003() {std::cout << "-- 析构函数 Destruct " << this << std::endl;}
    };
}

int main(void)
{
    std::cout << "Main thread start" << std::endl;
    ff::My_thread_003 my_thread_003; // 或者使用 匿名对象 传入（测试没法用）
    // 对象是被 拷贝（copy）到新线程中的
    std::thread t1(my_thread_003); // 传入可调用对象
    if (t1.joinable()) {
        t1.join(); // 阻塞主线程
    }
    std::cout << "Main thread stop" << std::endl;
    return 0;
}
