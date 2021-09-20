// forloop.cpp -- introducing the for loop
#include <iostream>
int main(void)
{
        using namespace std;
        int i; // 创建一个计数器 create a counter
        // 初始化;测试;更新 initialize; test; update
        for ( i = 0; i < 5; i ++ )
        {
                cout << "C++ knows loops.\n";
        }
        cout << "C++ knows when to stop.\n";
        return 0;
}
