// arrfun4.cpp -- functions with an array range
#include <iostream>
const int ArSize = 8;
int sum_arr (const int * begin, const int * end); // 原型 prototype
int main(void)
{
        using namespace std;
        int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
        // 某些系统需要在int之前加上static以启用数组初始化
        // some systems require preceding int with static to enable array initialization
        int sum = sum_arr(cookies, cookies + ArSize);
        cout << "Total cookies eaten: " << sum << endl;
        sum = sum_arr(cookies, cookies + 3); // 前3个元素 first 3 elements
        cout << "First three eaters ate " << sum << " cookies.\n";
        sum = sum_arr(cookies + 4, cookies + 8); // 后4个元素 last 4 elements
        cout << "Last four eaters ate " << sum << " cookies.\n";
        return 0;
}
// 返回一个整数数组的和 return the sum of an integer array
int sum_arr (const int * begin, const int * end)
{
        const int * pt;
        int total = 0;
        for ( pt = begin; pt != end; pt ++ )
        {
                total = total + *pt;
        }
        return total;
}
