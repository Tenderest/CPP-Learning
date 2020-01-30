// left.cpp -- string function with a default argument
#include <iostream>
const int ArSize = 80;
char * left (const char * str, int n = 1);
int main(void)
{
        using namespace std;
        char sample[ArSize];
        cout << "Enter a string:\n";
        cin.get(sample, ArSize);
        char * ps = left(sample, 4);
        cout << ps << endl;
        delete [] ps; // 释放的旧字符串 free old string
        ps = left(sample);
        cout << ps << endl;
        delete [] ps; // 释放新的字符串 free new string
        return 0;
}
// 此函数返回一个指向新字符串的指针，该字符串由str字符串中的前n个字符组成。
// This function returns a pointer to a new string consisting of the first n character in the str string.
char * left (const char * str, int n)
{
        if ( n < 0 )
        {
                n = 0;
        }
        char * p = new char[n + 1];
        int i;
        for ( i = 0; i < n && str[i]; i ++ )
        {
                p[i] = str[i]; // 复制字符 copy characters
        }
        while ( i <= n )
        {
                p[i++] = '\0'; // 将剩余的字符串设置为'\0' set reset of string to '\0'
        }
        return p;
}
