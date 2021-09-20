// arrayone.cpp -- small arrays of integers
#include <iostream>
int main(void)
{
        using namespace std;
        int yams[3]; // 创建包含三个元素的数组 creates array with three elements
        yams[0] = 7; // 为第一个元素赋值 assign value to first elements
        yams[1] = 8;
        yams[2] = 6;
        int yamcosts[3] = {20, 30, 5}; // 创建、初始化数组 create, initialize array
        // 注意:如果你的c++编译器或翻译不能初始化   NOTE: if your C++ compiler or translator can't initialize
        // 这个数组，使用static int yamcosts[3]代替 this array, use static int yamcosts[3] instead of
        // int yamcosts[3]
        cout << "Tootal yams = ";
        cout << yams[0] + yams[1] + yams[2] << endl;
        cout << "The patkage with " << yams[1] << " yams costs ";
        cout << yamcosts[1] << " cents per yam.\n";
        int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
        total = total + yams[2] * yamcosts[2];
        cout << "The total yam expenst is " << total << " cents.\n";
        cout << "\nSize of yams array = " << sizeof yams;
        cout << " bytes.\n";
        cout << "Size of one element = " << sizeof yams[0];
        cout << " bytes.\n"; // element 元素
        return 0;
}
