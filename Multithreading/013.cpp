#include <iostream>
#include <thread>
#include <mutex>
#include <future>

/**
 * std::future 模板的其他方法
 *   wait_for 会等待一定时间，返回一个枚举(类)类型，代表 future 对象的状态，返回的类型是 future_status
 */

namespace ff {
    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg &arg, const Args &... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }

    int my_thread_008() {
        std::cout << "-- my thread start ==> " << std::this_thread::get_id() << std::endl;
        std::chrono::milliseconds during(5000);
        std::this_thread::sleep_for(during);
        std::cout << "-- my thread stop  ==> " << std::this_thread::get_id() << std::endl;
        return 5;
    }
}

int main(void) {
    std::cout << "Main thread start ==> " << std::this_thread::get_id() << std::endl;
    std::future<int> ret_thread_005 = std::async(ff::my_thread_008);
    std::cout << "main continue ..." << std::endl;

    // std::cout << ret_thread_005.get() << std::endl; // 只有等待线程完毕才能获取结果
    /*
     * /// Status code for futures
     *     enum class future_status
     *     {
     *       ready,
     *       timeout,
     *       deferred
     *     };
     */
    std::future_status status = ret_thread_005.wait_for(std::chrono::seconds(6));
    // 等待 1 秒，实际线程执行完毕需要 5 秒钟，wait_for 会等待一定时间
    if (status == std::future_status::timeout) {
        // 超时表示线程没执行完
        std::cout << "std::future_status::timeout." << std::endl;
    } else if (status == std::future_status::ready) {
        // 表示成功返回
        std::cout << "std::future_status::ready" << std::endl;
        std::cout << ret_thread_005.get() << std::endl;
    } else if (status == std::future_status::deferred) {
        std::cout << "std::future_status::deferred" << std::endl;
        // 如果 async 创建时，第一个参数被设置为 std::launch::deferred 则本条件成立，线程被延迟执行
        // 主线程中执行，相当于函数调用
        std::cout << ret_thread_005.get() << std::endl;
    }
    std::cout << "Main thread stop  ==> " << std::this_thread::get_id() << std::endl;
    // 异步任务，主线程执行完之前会一直等待执行完毕
    return 0;
}
