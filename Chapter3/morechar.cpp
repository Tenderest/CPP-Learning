// morechar.cpp -- the char type and int type contrasted
#include <iostream>
int main(void)
{
        using namespace std;
        char ch = 'M'; // 将M的ASCII码赋给ch
        int i = ch;    // 在int中存储相同的代码
        cout << "The ASCII code for " << ch << " is " << i << endl;
        cout << "Add ore to the character code:" << endl;
        ch = ch + 1; // 更改ch中的字符代码
        i = ch;      // 在i中保存新字符代码
        cout << "The ASCII code for " << ch << " is " << i << endl;
        // 使用 cout.put（） 成员函数来显示字符
        cout << "Displaying char ch using cout.put(ch): ";
        cout.put(ch);
        // 使用cout.put()来显示char常量
        cout.put('!');
        cout << endl << "Done" << endl;
        return 0;
}
