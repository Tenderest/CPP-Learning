// funtemp.cpp -- using a function template
#include <iostream>
// 函数模板的原型 function template prototype
template <typename T> // or class T
void Swap (T & a, T & b);
int main(void)
{
        using namespace std;
        int i = 10;
        int j = 20;
        cout << "i, j = " << i << ", " << j << ".\n";
        cout << "Using compiler-generated int swapper:\n";
        Swap(i, j); // 生成void Swap(int &, int &) generates void Swap(int &, int &)
        cout << "Now i, j = " << i << ", " << j << ".\n";

        double x = 24.5;
        double y = 81.7;
        cout << "x, y = " << x << ", " << y << ".\n";
        cout << "Using compiler-generated double swapper:\n";
        Swap(x, y); // 生成void Swap(double &, double &) generates void Swap(double &, double &)
        cout << "Now x, y = " << x << ", " << y << ".\n";
        // cin.get();
        return 0;
}
// 函数模板定义 function template definition
template <typename T> // or class T
void Swap (T & a, T & b)
{
        T temp; // 临时变量的类型为T temp a variable of T
        temp = a;
        a = b;
        b = temp;
}
