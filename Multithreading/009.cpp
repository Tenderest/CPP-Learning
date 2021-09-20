#include <iostream>
#include <thread>
#include <mutex>
#include <future>

/**
 * std::async 一个模板，用来启动一个异步任务，返回一个 std::future 对象
 *   可以额外向 std::async() 传递一个参数，该参数类型是 std::launch() 是一个枚举类型，达到一些特殊目的
 *     a. std::launch::deferred （延迟调用）表示线程入口函数调用被延迟到 get() 或 wait() 函数的调用时才执行
 *       -- 没有创建新的线程出来，调试的时候线程 id 和主线程 id 是一样的
 *       -- 如果不调用，则线程不会被执行，实际上根本没创建
 *     b. std::launch::async 在调用模板创建的时候就创建了新线程，并且立即开始执行，不用等到 get() 或 wait()
 *   如果不加标记，为以下调用形式
 * template<typename _Fn, typename... _Args>
 *   inline future<__async_result_of<_Fn, _Args...>>
 *   async(_Fn&& __fn, _Args&&... __args)
 *   {
 *     return std::async(launch::async|launch::deferred,
 *                       std::forward<_Fn>(__fn),
 *                       std::forward<_Args>(__args)...);
 *   }
 * std::future 一个类模板 包含线程返回的结果，调用成员函数 get 获取
 */

namespace ff {
    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }
    
    int my_thread_005()
    {
        std::cout << "-- my thread start ==> " << std::this_thread::get_id() << std::endl;
        // std::cout << "-- my_thread id is: " << std::this_thread::get_id() << std::endl;
        std::chrono::milliseconds during(5000);
        std::this_thread::sleep_for(during);
        std::cout << "-- my thread stop  ==> " << std::this_thread::get_id() << std::endl;
        return 5;
    }
}

int main(void)
{
    std::cout << "Main thread start ==> " << std::this_thread::get_id() << std::endl;
    // std::cout << "主线程 id = " << std::this_thread::get_id() << std::endl;
    // std::future<int> ret_thread_005 = std::async(ff::my_thread_005);
    // auto ret_thread_005 = std::async(ff::my_thread_005);
    std::future<int> ret_thread_005 = std::async(ff::my_thread_005);
    // 这里使用的是函数（线程入口函数），也可以使用可调用对象，即重载了 函数调用运算符 的类对象
    // 用法和 std::thread 有些类似
    // ...
    // ...
    std::cout << "main continue ..." << std::endl;
    int m_i;
    m_i = 0;
    std::cout << ret_thread_005.get() << std::endl; // 只有等待线程完毕才能获取结果
    // std::cout << ret_thread_005.get() << std::endl; // 不能多次使用 get() 函数，只能调用一次！
    // ret_thread_005.wait(); // 只会等待，但不会返回结果，与 get() 不同
    std::cout << "Main thread stop  ==> " << std::this_thread::get_id() << std::endl;
    // 尽管不在程序中调用 get(), wait() 方法，程序仍然会在结束前（before return）执行到另一个线程中
    return 0;
}
