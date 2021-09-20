// inline.cpp -- using an inline function
#include <iostream>
// 内联函数定义an inline function definition
inline double square (double x)
{
        return x * x;
}
int main(void)
{
        using namespace std;
        double a, b;
        double c = 13.0;
        a = square(5.0);
        b = square(4.5 + 7.5); // 可以传递表达式 can pass expressions
        cout << "a = " << a << ", b = " << b << "\n";
        cout << "c = " << c;
        cout << ", c square = " << square(c++) << "\n";
        cout << "Now c = " << c << "\n";
        return 0;
}
