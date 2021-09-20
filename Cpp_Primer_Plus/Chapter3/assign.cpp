// init.cpp -- type changes on initialization
#include <iostream>
int main(void)
{
        using namespace std;
        cout.setf(ios_base::fixed, ios_base::floatfield); // 固定点（小数点）
        float tree = 3; // 整型转换为浮点型
        int guess(3.9832); // 双精度转换成整数
        int debt = 7.2E12; // 结果在c++中没有定义
        cout << "tree = " << tree << endl;
        cout << "guess = " << guess << endl;
        cout << "debt = " << debt << endl;
        return 0;
}
