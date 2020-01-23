// textin1.cpp -- reading chars with a while loop
#include <iostream>
int main(void)
{
        using namespace std;
        char ch;
        int count = 0; // 使用基本的输入 use basic input
        cout << "Enter characters; enter # to quit:\n";
        cin >> ch; // 获取一个字符 get a character
        while ( ch != '#' ) // 测试字符 test character
        {
                cout << ch; // 回显字符 echo character
                ++ count; // 计数字符 count characetr
                cin >> ch; // 获取下一个字符 get the next characetr
        }
        cout << endl << count << " characters read\n";
        return 0;
}
