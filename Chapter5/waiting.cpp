// waiting.cpp -- using clock() in a time-delay loop
#include <iostream>
#include <ctime> // 描述clock()函数，clock_t类型 describes clock() function, clock_t type
int main(void)
{
        using namespace std;
        cout << "Enter the delay time, in seconds: ";
        float secs;
        cin >> secs;
        clock_t delay = secs * CLOCKS_PER_SEC; // 转换为时钟刻度 convert to clotk ticks
        cout << "starting\a\n";
        clock_t start = clock();
        while ( clock() - start < delay ) // 等到时间过去 wait until time elapses
        {
                ; // 注意分号 note the semicolon
        }
        cout << "done \a\n";
        return 0;
}
