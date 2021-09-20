#include <iostream>
#include <thread>
#include <mutex>
#include <future>

/**
 * std::future 模板的其他方法
 *   wait_for 会等待一定时间，返回一个枚举(类)类型，代表 future 对象的状态，返回的类型是 future_status
 * std::shared_future 与 future 是一样的作用，同样是一个类模板，但是 get() 的实现不一样，可以共享
 *   不会创建新的线程，在主线程中执行
 *   如果使n用的是 future 对象转成 shared_future 对象，则不能再使用 future 对象去调用 get() 不然会报错
 *      inline shared_future<_Res>
 *        future<_Res>::share() noexcept
 *        { return shared_future<_Res>(std::move(*this)); }
 *   这样原来的 future 就为空了
 */

namespace ff {

    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }
    
    int my_thread_009(int par)
    {
        std::cout << "par: " << par << std::endl;
        std::cout << "-- my thread start ==> " << std::this_thread::get_id() << std::endl;
        std::chrono::milliseconds during(5000);
        std::this_thread::sleep_for(during);
        std::cout << "-- my thread stop  ==> " << std::this_thread::get_id() << std::endl;
        return 5;
    }

    void my_thread_009_2(std::future<int> &tmpf) // 注意参数
    {
        std::cout << "-- -- thread 009_2 start ==> " << std::this_thread::get_id << std::endl;
        auto ret = tmpf.get(); // 获取值，注意只能 get 一次否则会报异常
        std::cout << "-- -- ret: " << ret << std::endl;
        std::cout << "-- -- thread 009_2 stop ==> " << std::this_thread::get_id << std::endl;
        return;
    }

    void my_thread_009_3(std::shared_future<int> &tmpf) // 注意参数
    {
        std::cout << "-- -- thread 009_3 shared future start ==> " << std::this_thread::get_id << std::endl;
        auto ret = tmpf.get(); // 获取值，注意只能 get 一次否则会报异常
        std::cout << "-- -- ret: " << ret << std::endl;
        std::cout << "-- -- thread 009_3 shared future stop ==> " << std::this_thread::get_id << std::endl;
        return;
    }
}

int main(void)
{
    std::cout << "Main thread start ==> " << std::this_thread::get_id() << std::endl;

    std::packaged_task<int(int)> packagedTask(ff::my_thread_009);

    std::thread t1(std::ref(packagedTask), 11); // 存引用防止复制 std::ref()
    if (t1.joinable()) {
        t1.join();
    }

    std::cout << "sleep 1 second.. ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // std::future<int> ret_packaged_task = packagedTask.get_future(); // 因为 get_future() 只能获取一次 future 对象
    std::shared_future<int> sharedFuture(packagedTask.get_future()); // 直接构造
    // std::shared_future<int> sharedFuture(&ret_packaged_task);
    // std::shared_future<int> sharedFuture(ret_packaged_task.share());
    /*
     *     inline shared_future<_Res>
     *       future<_Res>::share() noexcept
     *       { return shared_future<_Res>(std::move(*this)); }
     */
    // bool can_get = ret_packaged_task.valid(); // 用于判断 future 对象能否获取有效值



    // std::thread t2(ff::my_thread_009_2, std::ref(ret_packaged_task));
    // 这步在线程函数中做了，不能再 get 获取了
    // std::cout << "ret_packaged_task: " << ret_packaged_task.get() << std::endl;
    // if (t2.joinable()) {
    //     t2.join();
    // }

    std::thread t3(ff::my_thread_009_3, std::ref(sharedFuture));
    std::thread t4(ff::my_thread_009_3, std::ref(sharedFuture));
    std::thread t5(ff::my_thread_009_3, std::ref(sharedFuture));
    if (t3.joinable() && t4.joinable() && t5.joinable()) {
        t3.join();
        t4.join();
        t5.join();
    }
    // ...
    // ...
    std::cout << "main continue ..." << std::endl;

    std::cout << "Main thread stop  ==> " << std::this_thread::get_id() << std::endl;
    return 0;
}
