// external.cpp -- external variables
// compile with support.cpp
#include <iostream>
using namespace std;
// external variables
double warming = 0.3; // warming的定义 warming defined
// 函数原型 function prototypes
void update (double dt);
void local ();
int main(void)
{ // 使用全局变量 uses global variable
        cout << "Global warming is " << warming << " degrees.\n";
        update(0.1); // 调用函数来改变warming call function to change warming
        cout << "Global warming is " << warming << " degrees.\n";
        local(); // 调用local函数来改变warming call function with local warming
        cout << "Global warming is " << warming << " degrees.\n";
        return 0;
}
