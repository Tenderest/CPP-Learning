#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <vector>

/**
 * std::packaged_task 一个模板，模板参数是各种可调用的对象，将它们包装起来，方便将来作为线程入口函数来调用
 *   std::packaged_task<ret_val(args type)>
 */

namespace ff {

    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }
    
    int my_thread_006(int par)
    {
        std::cout << "par: " << par << std::endl;
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

    std::packaged_task<int(int)> packagedTask(ff::my_thread_006);
    // std::packaged_task<ret_val(args type)>
    // packagedTask.operator()(1111); // packaged_task 也是一个可调用对象,重载了函数调用操作符
    // 但调用过一次后无法再继续调用!!! 但不会创建新的线程
    // std::future<int> future = packagedTask.get_future(); // 也可以获取 future

    // // 创建一组相同的 packaged_task 并放入容器
    // std::vector<std::packaged_task<int(int)>> vector_packaged_task;
    // std::packaged_task<int(int)> lambda_packagedTask([](int l_par){
    //     std::cout << "lambda par: " << l_par << std::endl;
    //     std::cout << "-- my Lambda thread start ==> " << std::this_thread::get_id() << std::endl;
    //     // std::cout << "-- my_thread id is: " << std::this_thread::get_id() << std::endl;
    //     std::chrono::milliseconds during(2000);
    //     std::this_thread::sleep_for(during);
    //     std::cout << "-- my Lambda thread stop  ==> " << std::this_thread::get_id() << std::endl;
    //     return 10;
    // });
    // vector_packaged_task.push_back(std::move(lambda_packagedTask)); // 移动语义
    // // 取出使用,用相同类型变量接收
    // std::packaged_task<int(int)> receive_pagdtask;
    // auto iterator = vector_packaged_task.begin();
    // receive_pagdtask = std::move(*iterator); // 移动语义
    // vector_packaged_task.erase(iterator); // 删除第一个元素,迭代器已经失效,后续代码无法使用
    // 后续操作相同

    std::packaged_task<int(int)> lambda_packagedTask([](int l_par){
        std::cout << "lambda par: " << l_par << std::endl;
        std::cout << "-- my Lambda thread start ==> " << std::this_thread::get_id() << std::endl;
        // std::cout << "-- my_thread id is: " << std::this_thread::get_id() << std::endl;
        std::chrono::milliseconds during(2000);
        std::this_thread::sleep_for(during);
        std::cout << "-- my Lambda thread stop  ==> " << std::this_thread::get_id() << std::endl;
        return 10;
    });

    std::thread t1(std::ref(packagedTask), 11); // 存引用防止复制 std::ref()
    if (t1.joinable()) {
        t1.join();
    }
    std::thread t2(std::ref(lambda_packagedTask), 22);
    if (t2.joinable()) {
        t2.join();
    }

    std::future<int> ret_packaged_task = packagedTask.get_future();
    std::cout << "ret_packaged_task: " << ret_packaged_task.get() << std::endl;

    std::future<int> ret_lambda_packaged_task = lambda_packagedTask.get_future();
    std::cout << "lambda packaged task: " << ret_lambda_packaged_task.get() << std::endl;
    // ...
    // ...
    std::cout << "main continue ..." << std::endl;
    int m_i;
    m_i = 0;

    std::cout << "Main thread stop  ==> " << std::this_thread::get_id() << std::endl;
    return 0;
}
