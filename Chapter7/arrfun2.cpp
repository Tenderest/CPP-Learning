// arrfun2.cpp -- functions with an array argument
#include <iostream>
const int ArSize = 8;
int sum_arr (int arr[], int n); // 原型 prototype
// 使用std::而不是使用指令 use std:: instead of using directive
int main(void)
{
        int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
        // 某些系统需要在int之前加上static以启用数组初始化
        // some systems require preceding int with static to enable array initialization
        std::cout << cookies << " = array address, ";
        // 有些系统需要类型转换:unsigned (cookie) some system require a type case; unsigned (cookies)
        std::cout << sizeof cookies << " = sizeof cookies\n";
        int sum = sum_arr(cookies, ArSize);
        std::cout << "Total cookies eaten: " << sum << std::endl;
        sum = sum_arr(cookies, 3); // 一个谎言 a lie
        std::cout << "First three eaters ate " << sum << " cookies.\n";
        sum = sum_arr(cookies + 4, 4); // 另一个谎言 another lie
        std::cout << "Last four eaters ate " << sum << " cookies.\n";
        return 0;
}
// 返回一个整数数组的和 return the sum of an integer array
int sum_arr (int arr[], int n)
{
        int total = 0;
        std::cout << arr << " = arr, ";
        // 有些系统需要类型转换:unsigned (arr) some systems require a type case: unsigned (arr)
        std::cout << sizeof arr << " = sizeof arr\n";
        for ( int i = 0; i < n; i ++ )
        {
                total = total + arr[i];
        }
        return total;
}
