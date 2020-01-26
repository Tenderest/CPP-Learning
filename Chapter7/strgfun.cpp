// strgfun.cpp -- functions with a string argument
#include <iostream>
unsigned int c_in_str (const char * str, char ch);
int main(void)
{
        using namespace std;
        char mmm[15] = "minimum"; // 数组中的字符串 string in an array
        // 一些系统要求在char之前加上static以启用数组初始化
        // some systems require preceding char with static to enable array initialization
        char * wail = "ululate"; // wail指向string wail points to string
        unsigned int ms = c_in_str(mmm, 'm');
        unsigned int us = c_in_str(wail, 'u');
        cout << ms << " m characters in " << mmm << endl;
        cout << us << " u characters in " << wail << endl;
        return 0;
}
// 这个函数计算ch字符的数量
// this function counts the number of ch characters
unsigned int c_in_str (const char * str, char ch)
{
        unsigned int count = 0;
        while ( *str ) // 当*str为'\0'时退出 quit when *str is '\0'
        {
                if ( *str == ch )
                {
                        count ++;
                }
                str ++; // 将指针移到下一个字符 move pointer to next char
        }
        return count;
}
