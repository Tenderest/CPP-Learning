#include <iostream>
#include <thread>
#include <string>

/**
 * 一：传递临时对象作为线程参数
 * (1.1)要避免的陷阱(解释1)
 * 
 * 自己编写一个类测试
 * 
 * 二：临时对象作为线程参数继续讲
 *（2.1）线程id 每个线程都有id std::this_thread::get_id()
 *（2.2）临时对象构造时机抓捕
 */

namespace ff {
    // void my_thread_004(const int& i, char* buf)
    void my_thread_004(const int& i, const std::string& buf)
    {
        std::cout << "-- my thread start" << std::endl;
        std::cout << std::this_thread::get_id() << std::endl;
        std::cout << i << " <--> " << buf << std::endl;
        // 分析认为，i 并不是 var 的引用，实际是值传递，可以认为是安全的
        // 指针在 detach 子线程时，绝对会有问题
        // string 引用和 前面的有些类似
        std::cout << "-- my thread stop" << std::endl;
    }

    class TT {
        // 通过看 thread 源码发现传递 函数 和 参数 的时候用的是 模板，使用了 std::forward
        // 尝试使用 右值引用 来达到完美转发
        /**
        template<typename _Callable, typename... _Args>
            explicit
            thread(_Callable&& __f, _Args&&... __args)
            {
        #ifdef GTHR_ACTIVE_PROXY
            // Create a reference to pthread_create, not just the gthr weak symbol.
            auto __depend = reinterpret_cast<void(*)()>(&pthread_create);
        #else
            auto __depend = nullptr;
        #endif
                _M_start_thread(_S_make_state(
                __make_invoker(std::forward<_Callable>(__f),
                        std::forward<_Args>(__args)...)),
                __depend);
            }
         */
        private:
            int m_i;
        public:
            TT()
            {
                std::cout << "[TT::TT()] 没有参数的构造函数, " << this << ", thread id = " << std::this_thread::get_id() << std::endl;
            }
            TT(int i) : m_i(i)
            {
                std::cout << "[TT::TT(int i)] 构造函数, " << this << ", thread id = " << std::this_thread::get_id() << std::endl;
            }
            TT(const TT& copy_TT) : m_i(copy_TT.m_i)
            {
                std::cout << "[TT::TT(const TT& copy_TT)] 拷贝构造函数, 构造了 " << this << " 从 " << &copy_TT << "拷贝来的" << ", thread id = " << std::this_thread::get_id() << std::endl;
            }
            TT(const TT&& right_value_TT) : m_i(right_value_TT.m_i)
            {
                std::cout << "[TT::TT(const TT&& right_value_TT)]（右值引用）拷贝构造函数, 构造了 " << this << " 从 " << &right_value_TT << "拷贝来的" << ", thread id = " << std::this_thread::get_id() << std::endl;
            }
            ~TT()
            {
                std::cout << "[TT::~TT()] 析构函数, " << this << ", thread id = " << std::this_thread::get_id() << std::endl;
            }
    };

    void my_thread_004_TT(const TT& thread_TT)
    {
        std::cout << "-- my thread start" << std::endl;
        std::cout << "子线程 my_thread_005 的参数地址是 " << &thread_TT << ", thread id = " << std::this_thread::get_id() << std::endl;
        std::cout << "-- my thread stop" << std::endl;
    }
}

int main(void)
{
    std::cout << "Main thread start" << std::endl;
    std::cout << "主线程 id = " << std::this_thread::get_id() << std::endl;
    int var = 004;
    char buf[] = "This is a test!";
    // std::thread t1(ff::my_thread_004, var, buf); // 这里可能出现，当调用 detach 时候可能在主线程结束的时候才传递
    // 可以自己写一个类进行测试，只需要 构造，拷贝构造，析构函数
    // std::thread t1(ff::my_thread_004, var, std::string(buf)); // 这里直接将 buf 转换成 string
    // std::thread t1(ff::my_thread_004_TT, var);
    std::thread t1(ff::my_thread_004_TT, ff::TT(var));
    if (t1.joinable()) {
        t1.join(); // 阻塞主线程
        // t1.detach(); // 出现问题的调用
    }
    std::cout << "Main thread stop" << std::endl;
    return 0;
}
