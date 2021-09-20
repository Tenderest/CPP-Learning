// strtype1.cpp -- using the C++ string class
#include <iostream>
#include <string> // 使字符串类可用 make string class available
int main(void)
{
        using namespace std;
        char charr1[20]; // 创建一个空数组 create an empty array
        char charr2[20] = "jaguar"; // 创建一个初始化的数组 create an initialized array
        string str1; // 创建一个空字符串对象 create an empty string object
        string str2 = "panther"; // 创建一个初始化的字符串 create an initilized string
        cout << "Enter a kind of feline: ";
        cin >> charr1;
        cout << "Enter another kind of feline: ";
        cin >> str1; // 使用cin进行输入 use cin for input
        cout << "Here are some felines: \n";
        cout << charr1 << " " << charr2 << " "
             << str1 << " " << str2 // 使用cout作为输出 use cout for output
             << endl;
        cout << "The third letter in " << charr2 << " is "
             << charr2[2] << endl;
        cout << "The third letter in " << str2 << " is "
             << str2[2] << endl; // 使用数组表示法 use array notation
        return 0;
}
