// strgback.cpp -- a function that returns a pointer to char
#include <iostream>
char * buildstr (char c, int n); // 原型 prototype
int main(void)
{
        using namespace std;
        int times;
        char ch;
        cout << "Enter a character: ";
        cin >> ch;
        cout << "Enter an integer: ";
        cin >> times;
        char * ps = buildstr(ch, times);
        cout << ps << endl;
        delete [] ps; // 释放内存 free memory
        ps = buildstr('+', 20); // 重用指针 reuse pointer
        cout << ps << "-Done-" << ps << endl;
        delete [] ps; // 释放内存 free memory
        return 0;
}
char * buildstr (char c, int n)
{
        char * pstr = new char[n + 1];
        pstr[n] = '\0'; // 终止字符串 terminate string
        while ( n -- > 0 )
        {
                pstr[n] = c; // 填充其余的字符串 fill reset of string
        }
        return pstr;
}
