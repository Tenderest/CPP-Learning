// 程序清单2.2 carrots.cpp
// carrots.cpp -- food processing program
// uses and displays a variable
#include <iostream>
int main(void)
{
        using std::cout;
        using std::cin;
        using std::endl;
        // using namespace std;
        
        int carrots; // 声明一个整数变量
        carrots = 25; // 为变量赋值
        cout << "I have ";
        cout << carrots; // 显示变量的值
        cout << " carrots.";
        cout << endl;
        carrots = carrots - 1; // 修改变量
        cout << "Crunch, crunch, Now I have " << carrots << " carrots." << endl;
        return 0;
}
