// textin3.cpp -- reading chars to end of file
#include <iostream>
int main(void)
{
        using namespace std;
        char ch;
        int count = 0;
        cin.get(ch); // 尝试读取一个字符 attempt to read a char
        while ( cin.fail() == false ) // 测试EOF test for EOF
        {
                cout << ch; // 回显字符 echo character
                ++ count;
                cin.get(ch); // 尝试读取另一个字符 attempt to read another char
        }
        cout << endl << count << " characters read\n";
        return 0;
}
