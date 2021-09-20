#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>

/**
 * a. std::atomic 续谈
 *      一般 atomic 原子操作，针对 ++, --, +=, -=, &=, |=, ~=(符合操作) 等是支持的，其他的可能不支持
 * b. std::async 深入谈
 *      1. std::async 参数详述
 *      2. std::async 和 std::thread 的区别
 *      3. std::async 不确定性问题的解决
 *    async 用来创建一个异步任务
 *    1. line 58 讲解
 *    std::thread() 如果系统资源紧张，那么可能创建线程就会失败，那么执行 std::thread() 时整个程序可能崩溃
 *    std::async() 我们一般不叫创建线程（解释 async能够创建线程），我们一般叫它创建一个异步任务，async 和 std::thread 最明显的不同，
 *    就是 async有时候并不创建新线程
 *      a)如果你用 std::launch::deferred 来调用 async 会怎么样??
 *        具体参考 010.cpp 中的描述，此处作复制粘贴
 *        没有创建新的线程出来，调试的时候线程 id 和主线程 id 是一样的
 *      b) std::launch::async 强制这个异步任务在新线程上执行，这意味着系统必须要给我创建出新线程来运行（也可参考 010.cpp ）
 *      c) 如果两个标记同时使用即 std::launch::async | std::launch::deferred 这样使用
 *         则由 async 自己选择
 *         这里贴出不加任何标记的 async 创建时的代码
 *        /// async, potential overload
 *        template<typename _Fn, typename... _Args>
 *          inline future<__async_result_of<_Fn, _Args...>>
 *          async(_Fn&& __fn, _Args&&... __args)
 *          {
 *            return std::async(launch::async|launch::deferred,
 *                  std::forward<_Fn>(__fn),
 *                  std::forward<_Args>(__args)...);
 *          }
 *         可以看出不加任何标记和两个标记一起加是一样的，源码可以查看，即可以资源足够分配的时候创建新线程，不够的时候延迟调用且不创建新线程
 *         交给系统决定
 *        /// async
 *        template<typename _Fn, typename... _Args>
 *          future<__async_result_of<_Fn, _Args...>>
 *          async(launch __policy, _Fn&& __fn, _Args&&... __args)
 *          {
 *            std::shared_ptr<__future_base::_State_base> __state;
 *            if ((__policy & launch::async) == launch::async)
 *          {
 *            __try
 *              {
 *                __state = __future_base::_S_make_async_state(
 *                std::thread::__make_invoker(std::forward<_Fn>(__fn),
 *                                std::forward<_Args>(__args)...)
 *                );
 *              }
 *      #if __cpp_exceptions
 *            catch(const system_error& __e)
 *              {
 *                if (__e.code() != errc::resource_unavailable_try_again
 *                || (__policy & launch::deferred) != launch::deferred)
 *              throw;
 *              }
 *      #endif
 *          }
 *            if (!__state)
 *          {
 *            __state = __future_base::_S_make_deferred_state(
 *                std::thread::__make_invoker(std::forward<_Fn>(__fn),
 *                            std::forward<_Args>(__args)...));
 *          }
 *            return future<__async_result_of<_Fn, _Args...>>(__state);
 *          }
 *
 *      d) 不带任何启动参数，只有线程入口函数，见 line 35
 *    2. std::async 和 std::thread 的区别
 *      std::thread() 如果系统资源紧张，那么可能创建线程就会失败，那么执行 std::thread() 时整个程序可能崩溃
 *      std::thread 方式创建线程想要拿到返回值不太方便
 *      std::async 创建异步任务，可能创建线程也可能不创建线程，也很容易拿到线程入口函数的返回值
 *      如果一定要创建新线程则使用 std::launch::async 标记即可
 *      经验：一个程序中线程数量一般不宜超过 100-200 个
 *    3. std::async 不确定性问题的解决
 *      不加额外参数的调用让系统自行决定是否创建新线程，问题焦点就在于这个异步任务有没有被推迟执行
 *      可以使用 std::future 对象的 wait_for() 函数，可以参考 013.cpp 文件
 *      这里有一个 0s 的写法，其实是 std::chrono 重载的运算符 "" 的写法，不知道怎么做的，可能是字面量
 *      可以用下面的代码调试查看
 *      std::future_status status = ret_thread_005.wait_for(0s) // (std::chrono::seconds(6));
 *      if (status == std::future_status::deferred) {
 *          std::cout << "std::future_status::deferred" << std::endl;
 *          // 线程被延迟执行
 *          std::cout << ret_thread_005.get() << std::endl;
 *      } else {
 *          if (status == std::future_status::ready) {
 *              // 表示成功返回
 *              std::cout << "std::future_status::ready" << std::endl;
 *              std::cout << ret_thread_005.get() << std::endl;
 *          } else if (status == std::future_status::timeout) {
 *              // 超时表示线程没执行完
 *              std::cout << "std::future_status::timeout." << std::endl;
 *          }
 *      }
 */

std::atomic<int> g_atomic_count(0);

namespace ff {

    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }
    
    void my_thread_011()
    {
        for (int i = 0; i < 1000000; ++i) {
            g_atomic_count++; // 对应的操作是原子操作了
            // g_atomic_count += 1;
            // g_atomic_count = g_atomic_count + 1; // 结果错误
        }
    }

    int my_thread_011_01_async()
    {
        std::cout << "-- thread id --> " << std::this_thread::get_id() << " start --" << std::endl;
        std::cout << "-- thread id --> " << std::this_thread::get_id() << " stop --" << std::endl;
        return std::rand()%10000;
    }

}

int main(void)
{
    std::cout << "Main thread start ==> " << std::this_thread::get_id() << std::endl;
    std::thread t1(ff::my_thread_011);
    std::thread t2(ff::my_thread_011);
    if (t1.joinable() && t2.joinable()) {
        t1.join(); t2.join();
    }

    std::cout << "g_atomic_count: " << g_atomic_count << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::future<int> ret_async = std::async(ff::my_thread_011_01_async);
    // std::launch::deferred 延迟调用 std::launch::async 强制创建一个新线程
    std::cout << "ret_async: " << ret_async.get() << std::endl;

    std::cout << "Main thread stop  ==> " << std::this_thread::get_id() << std::endl;
    return 0;
}
