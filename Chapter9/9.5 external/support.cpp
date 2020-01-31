// support.cpp -- use external variable
// compile with external.cpp
#include <iostream>
extern double warming; // 使用来自另一个文件的warming use warming from another file
// 函数原型 function prototypes
void update (double dt);
void local ();
using std::cout;
void update (double dt) // 修改全局变量 modifies global variable
{
        extern double warming; // 可选的重新声明 optional redeclarotion
        warming += dt; // 使用全局变量warming uses global warming
        cout << "Updating global warming to " << warming;
        cout << " degrees.\n";
}
void local() // 新变量隐藏外部变量 new variable hides external one
{
        double warming = 0.8;
        cout << "Local warming = " << warming << " degrees.\n";
        // 使用范围解析运算符访问全局变量
        // Access global variable with the scope resolution operator
        cout << "But global warming = " << ::warming;
        cout << " degrees.\n";
}
