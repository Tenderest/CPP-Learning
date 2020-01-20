// choices.cpp -- array variations
#include <iostream>
#include <vector> // STL C++98
#include <array> // C++11
int main(void)
{
        using namespace std;
        // C，原始C ++ C, original C++
        double a1[4] = {1.2, 2.4, 3.6, 4.8};
        // C++98 STL
        vector<double> a2(4); // 创建具有4个元素的向量 creatc vector with 4 elements
        // 在C98中没有简单的初始化方法 no simple way to initialize in C98
        a2[0] = 1.0 / 3.0;
        a2[1] = 1.0 / 5.0;
        a2[2] = 1.0 / 7.0;
        a2[3] = 1.0 / 9.0;
        // C++11 -- 创建和初始化数组对象 C++11 -- create and initialize array object
        array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
        array<double, 4> a4;
        a4 = a3; // 对于相同大小的数组对象有效 valid for array object of same size
        // 使用数组表示法 use array notation
        cout << "a1[2] : " << a1[2] << " at " << &a1[2] << endl;
        cout << "a2[2] : " << a2[2] << " at " << &a2[2] << endl;
        cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
        cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl;
        // 行为不当 misdeed
        a1[-2] = 20.2;
        cout << "a1[-2] : " << a1[-2] << " at " << &a1[-2] << endl;
        cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
        cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl;
        return 0;
}
