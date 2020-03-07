// strngbad.cpp -- StringBad class methods
#include <cstring> // string.h for some
#include <ostream>
#include "strngbad.h"
using std::cout;

// 初始化静态类成员 initializing static class member
int StringBad::num_strings = 0;

// 类方法 class methods
// 来自C字符串的构造函数StringBad constructor StringBad from C string
StringBad::StringBad (const char * s)
{
        len = std::strlen(s); // 设置大小 set size
        str = new char[len + 1]; // 分配存储空间 allot storage
        std::strcpy(str, s); // 初始化指针 initialize pointer
        num_strings ++; // 设置对象计数 set object count
        cout << num_strings << ": \"" << str << "\" object created\n"; // 供您参考 For Your Information
}

StringBad::StringBad ()
{
        len = 4;
        str = new char[4];
        std::strcpy(str, "C++"); // 默认字符串 default string
        num_strings ++;
        cout << num_strings << ": \"" << str << "\" default object created\n"; // 供您参考 For Your Information
}

StringBad::~StringBad () // 必要的析构函数 necessary destructor
{
        cout << "\"" << str << "\" object deleted, "; // FYI
        -- num_strings; // 必填 required
        cout << num_strings << "left\n"; // FYI
        delete [] str; // 必填 required
}

std::ostream & operator<< (std::ostream & os, const StringBad & st)
{
        os << st.str;
        return os;
}
