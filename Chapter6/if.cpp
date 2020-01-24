// if.cpp -- using the if statement
#include <iostream>
int main(void)
{
        using std::cin; // 使用声明 using declarations
        using std::cout;
        char ch;
        int spaces = 0;
        int total = 0;
        cin.get(ch);
        while ( ch != '.' ) // 句子结束时退出 quit at end of sentence
        {
                if ( ch == ' ' ) // 检查ch是否为空格 check if ch is a space
                {
                        ++ spaces;
                }
                ++ total; // 每次都做 done every time
                cin.get(ch);
        }
        cout << spaces << " spaces, " << total;
        cout << " characters total in sentence\n";
        return 0;
}
