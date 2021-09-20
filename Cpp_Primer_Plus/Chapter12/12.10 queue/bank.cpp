// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <ios>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer (double x); // 有新客户吗？ is there a new customer?

int main(void)
{
        using std::cin;
        using std::cout;
        using std::endl;
        using std::ios_base;
        // 设置内容 setting things up
        std::srand(std::time(0)); // 随机初始化rand() random initializing of rand()

        cout << "Case Study: Bank of Heather Auto matic Teller\n";
        cout << "Enter maximum size of queue: ";
        int qs;
        cin >> qs;
        Queue line(qs); // line队列最多可容纳qs个人 line queue holds up to qs people

        cout << "enter the number of simulation hours: ";
        int hours;     // 模拟时间 hours of simulation
        cin >> hours;
        // 模拟将运行每分钟的周期 simulation will run 1 cycle per minute
        long cyclelimit = MIN_PER_HR * hours; // 周期数 # of cycles

        cout << "Enter the average number of customers per hour: ";
        double perhour;      // 每小时平均到达次数 average # of arrival per hour
        cin >> perhour;
        double min_per_cust; // 平均到达时间 average time between arrivals
        min_per_cust = MIN_PER_HR / perhour;

        Item temp;            // 新的客户数据 new customer data
        long turnaways = 0;   // 被排满的人拒之门外 turned awway by full queue
        long customers = 0;   // 加入队列 joined the queue
        long served = 0;      // 在模拟期间服务 served during the simulation
        long sum_line = 0;    // 累积队伍长度 cumulative line length
        int wait_time = 0;    // 直到ATM空闲的时间 time until autoteller is free
        long line_wait = 0;   // 累计排队时间 cumulative time in line

        // 运行模拟 running the simulation
        for ( int cycle = 0; cycle < cyclelimit; cycle ++ )
        {
                if ( newcustomer(min_per_cust) )
                {
                        if ( line.isfull() )
                        {
                                turnaways ++;
                        }
                        else
                        {
                                customers ++;
                                temp.set(cycle);
                                line.enqueue(temp);
                        }
                }
                if ( wait_time <= 0 && !line.isempty() )
                {
                        line.dequeue(temp);
                        wait_time = temp.ptime();
                        line_wait += cycle - temp.when();
                        served ++;
                }
                if ( wait_time > 0 )
                {
                        wait_time --;
                }
                sum_line += line.queuecount();
        }
        
        // 报告结果 reporting results
        if ( customers > 0 )
        {
                cout << "customers accepted: " << customers << endl;
                cout << "  customers served: " << served << endl;
                cout << "         turnaways: " << turnaways << endl;
                cout << "average queue size: ";
                cout.precision(2);
                cout.setf(ios_base::fixed, ios_base::floatfield);
                cout << (double) sum_line / cyclelimit << endl;
                cout << "average wait time: "
                     << (double) line_wait / served << " minutes\n";
        }
        else
        {
                cout << "No customers!\n";
        }
        cout << "Done!\n";
        return 0;
}

// x =客户之间的平均时间（以分钟为单位） x = average time, in minutes, between customers
// 如果客户在这一分钟出现，则返回值为true return value is true if customer shows up this minute
bool newcustomer (double x)
{
        return (std::rand() * x / RAND_MAX < 1);
}
