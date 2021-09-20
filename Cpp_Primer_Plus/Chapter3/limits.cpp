// limits.cpp -- some integer limits
#include <iostream>
#include <climits> // use climits.h for older systems
int main(void)
{
        using namespace std;
        int n_int = INT_MAX; // 初始化n_int为最大int值
        short n_short = SHRT_MAX; // 在climits文件中定义的符号
        long n_long = LONG_MAX;
        long long n_llong = LLONG_MAX;
        // sizeof运算符生成类型或变量的大小
        cout << "int is " << sizeof(int) << " bytes." << endl;
        cout << "short is " << sizeof n_short << " bytes." << endl;
        cout << "long is " << sizeof n_long << " bytes." << endl;
        cout << "long long is " << sizeof n_llong << " bytes." << endl;
        cout << endl;
        cout << "Maximum values: " << endl;
        cout << "int: " << n_int << endl;
        cout << "short: " << n_short << endl;
        cout << "long: " << n_long << endl;
        cout << "long long: " << n_llong << endl << endl;
        cout << "Minimum int value = " << INT_MIN << endl;
        cout << "Bits per byte = " << CHAR_BIT << endl;
        return 0;
}
