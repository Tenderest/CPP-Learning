// cctypes.cpp -- using the ctype.h library
#include <iostream>
#include <cctype> // 字符函数原型 prototypes for character functions
int main(void)
{
        using namespace std;
        cout << "Enter text for analysis, and type @"
                " to terminate input.\n";
        char ch;
        int whitespace = 0;
        int digits = 0;
        int chars = 0;
        int punct = 0;
        int others = 0;
        cin.get(ch); // 获取第一个字符 get first character
        while ( ch != '@' ) // 哨兵测试 test for sentinel
        {
                if ( isalpha(ch) ) // 它是一个字母字符吗? is it an alphabetic character?
                {
                        chars ++;
                }
                else if( isspace(ch) ) // 它是空白字符吗? is it a whitespace character?
                {
                        whitespace ++;
                }
                else if ( isdigit(ch) ) // 是数字吗? is it a digit?
                {
                        digits ++;
                }
                else if( ispunct(ch) ) // 标点符号吗? is it punctuation?
                {
                        punct ++;
                }
                else
                {
                        others ++;
                }
                cin.get(ch); // 获取下一个字符 get next character
        }
        cout << chars << " letters, "
             << whitespace << " whitespace, "
             << digits << " digits, "
             << punct << " punctuations, "
             << others << " others.\n";
        return 0;
}
