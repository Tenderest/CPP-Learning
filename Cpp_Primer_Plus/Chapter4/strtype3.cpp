// strtype3.cpp -- more string class features
#include <iostream>
#include <string> // 使字符串类可用 make string class available
#include <cstring> // c风格的字符串库 C-style string library
int main(void)
{
        using namespace std;
        char charr1[20];
        char charr2[20] = "jaguar";
        string str1;
        string str2 = "panther";
        // 字符串对象和字符数组的赋值 assignment for string objects and character arrays
        str1 = str2; // 复制str2到str1 copy str2 to str1
        strcpy(charr1, charr2); // 复制charr2到charr1 copy charr2 to charr1
        // 附加字符串对象和字符数组 appending for string objects and character arrays
        str1 += " paste"; // 在str1结尾添加粘贴 add paste to end of str1
        strcat(charr1, " juice"); // 在charr1结尾添加juice add juice to end of charr1
        // 查找字符串对象和 C 样式字符串的长度 finding the length of a string object and a C-style string
        int len1 = str1.size(); // 获取str1的长度 obtain length of str1
        int len2 = strlen(charr1); // 获取charr1的长度 obtain length of charr1
        cout << "The string " << str1 << " contains "
             << len1 << " characters.\n";
        cout << "The string " << charr1 << " contains "
             << len2 << " characters.\n";
        return 0;
}
