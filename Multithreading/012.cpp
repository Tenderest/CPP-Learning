#include <iostream>
#include <thread>
#include <mutex>
#include <future>

/**
 * std::promise 一个模板
 * 可以在某个线程中给它赋值,之后在其他线程取出来用
 * 通过 promise 保存一个值,在将来某个时刻绑定到 future 上来获取这个保存的值
 */

namespace ff {

    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }
    
    void my_thread_007(std::promise<int> &tmp_promise, int calc)
    {
        std::cout << "calc: " << calc << std::endl;
        std::cout << "-- my thread start ==> " << std::this_thread::get_id() << std::endl;
        // calculate.. ...
        std::chrono::milliseconds during(5000);
        std::this_thread::sleep_for(during);
        calc += std::rand()%10000;
        tmp_promise.set_value(calc); // 将结果保存到了 tmp_promise 对象中
        std::cout << "-- my thread stop  ==> " << std::this_thread::get_id() << std::endl;
        // return ;
    }

}

int main(void)
{
    std::cout << "Main thread start ==> " << std::this_thread::get_id() << std::endl;
    // std::cout << "主线程 id = " << std::this_thread::get_id() << std::endl;

    std::promise<int> promise; // 对象中保存值的类型为 int
    std::thread t1(ff::my_thread_007, std::ref(promise), 12);
    if (t1.joinable()) {
        t1.join();
    }

    // 获取结果值
    std::future<int> ret_promise = promise.get_future();
    std::cout << "ret_promise: " << ret_promise.get() << std::endl; // get() 只能调用一次,不能调用多次
    // ...
    // ...
    std::cout << "main continue ..." << std::endl;
    int m_i;
    m_i = 0;

    std::cout << "Main thread stop  ==> " << std::this_thread::get_id() << std::endl;
    return 0;
}
