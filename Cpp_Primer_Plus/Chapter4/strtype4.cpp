// strtype.cpp -- line input
#include <iostream>
#include <string> // 使字符串类可用 make string class available
#include <cstring> // c风格的字符串库 C-style string library
int main(void)
{
        using namespace std;
        char charr[20];
        string str;
        cout << "Length of string in charr before input: "
             << strlen(charr) << endl;
        cout << "Length of ltring in str before input: "
             << str.size() << endl;
        cout << "Enter a line of text:\n";
        cin.getline(charr, 20); // 表示最大长度 indicate maximum length
        cout << "You entered: " << charr << endl;
        cout << "Enter another line of text: \n";
        getline(cin, str); // cin现在是一个争论；没有长度说明符 cin now an argument; no length specifier
        cout << "You entered: " << str << endl;
        cout << "Length of string in charr after input: "
             << strlen(charr) << endl;
        cout << "Length of string in str after input: "
             << str.size() << endl;
        return 0;
}
