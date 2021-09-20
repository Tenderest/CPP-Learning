#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

/**
 * std::atomic 原子操作 一个类模板
 *   用来封装某个类型的值的
 * 问题引入：一个线程在读取，一个线程在写入，会导致问题
 *   操作进行到一半的时候被打断，导致操作失误
 *
 * 可以理解成一种：不需要用到互斥量加锁（无锁）技术的多线程并发编程方式
 * 原子操作：是在多线程中不会被打断的程序执行片段
 * 原子操作：一般指“不可再分割的操作”
 */

// int g_count = 0;
// std::atomic<int> g_atomic_count = 0; // 可以像操作 int 类型变量一样来操作
std::atomic<int> g_atomic_count(0);
std::atomic_bool g_atomic_bool(false); // 相当于 ==> std::atomic<bool> g_atomic_bool = false;
/*
 * 其实是各种 typedef
 * /// atomic_bool
  typedef atomic<bool>			atomic_bool;

  /// atomic_char
  typedef atomic<char>			atomic_char;

  /// atomic_short
  typedef atomic<short>			atomic_short;

  /// atomic_int
  typedef atomic<int>			atomic_int;

  /// atomic_int8_t
  typedef atomic<int8_t>		atomic_int8_t;

  typedef atomic<int16_t>		atomic_int16_t;

  /// atomic_uint16_t
  typedef atomic<uint16_t>		atomic_uint16_t;

  /// atomic_int32_t
  typedef atomic<int32_t>		atomic_int32_t;

  /// atomic_int64_t
  typedef atomic<int64_t>		atomic_int64_t;
 */
// std::mutex mutex;
namespace ff {

    void print() {}

    template<typename Arg, typename... Args>
    void print(const Arg& arg, const Args&... args) {
        std::cout << "-- " << arg << std::endl;
        print(args...);
    }
    
    void my_thread_010()
    {
        // std::cout << "-- my thread start ==> " << std::this_thread::get_id() << std::endl;
        // std::cout << "-- my thread stop  ==> " << std::this_thread::get_id() << std::endl;
        for (int i = 0; i < 1000000; ++i) {
            // mutex.lock();
            // g_count++;
            g_atomic_count++; // 对应的操作是原子操作了
            // mutex.unlock();
        }
        // 此时不加锁有可能出现值小于 1000000*2 的情况
    }

    void my_thread_010_1() {
        std::chrono::seconds during(1);
        while (g_atomic_bool == false) {
            std::cout << "-- thread id: " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(during);
        }
        std::cout << "-- thread " << std::this_thread::get_id() << " stop!!" << std::endl;
    }
}

int main(void)
{
    std::cout << "Main thread start ==> " << std::this_thread::get_id() << std::endl;
    std::thread t1(ff::my_thread_010);
    std::thread t2(ff::my_thread_010);
    if (t1.joinable() && t2.joinable()) {
        t1.join(); t2.join();
    }

    // std::cout << "g_count: " << g_count << std::endl;
    std::cout << "g_atomic_count: " << g_atomic_count << std::endl;
    std::cout << "----------------------------------" << std::endl;

    std::thread t3(ff::my_thread_010_1);
    std::thread t4(ff::my_thread_010_1);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    g_atomic_bool = true;
    if (t3.joinable() && t4.joinable()) {
        t3.join(); t4.join();
    }
    std::cout << "Main thread stop  ==> " << std::this_thread::get_id() << std::endl;
    return 0;
}
