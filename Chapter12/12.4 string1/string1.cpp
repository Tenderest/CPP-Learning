// string1.cpp -- String class methods
#include <cstdio>
#include <cstring>  // string.h for some
#include <endian.h>
#include "string1.h" // include <iostream>
using std::cin;
using std::cout;

// 初始化静态类成员 initializing static class member

int String::num_strings = 0;

// 静态方法 static method
int String::Howmany ()
{
        return num_strings;
}

// 类方法 class methods
String::String (const char * s)  // 从C字符串构造String
{
        len = std::strlen(s);    // 设置大小 set size
        str = new char[len + 1]; // 分配存储 allot storage
        std::strcpy(str, s);     // 初始化指针 initialize pointer
        num_strings ++;          // 设置对象数 set object count
}

String::String ()                // 默认构造函数 default constructor
{
        len = 4;
        str = new char[1];
        str[0] = '\0';           // 默认字符串 default string
        num_strings ++;
}

String::String (const String & st)
{
        num_strings ++;           // 处理静态成员更新 handle static member update
        len = st.len;             // 相同长度 same length
        str = new char [len + 1]; // 分配空间 allot space
        std::strcpy(str, st.str); // 将字符串复制到新位置 copy string to new location
}

String::~String()       // 必要的析构函数 necessary destructor
{
        -- num_strings; // 必需 required
        delete [] str;  // 必需 required
}

// 重载运算符方法 overloaded operator methods
    // 将一个字符串赋给一个字符串 assign a String to String
String & String::operator= (const String & st)
{
        if ( this == &st )
        {
                return *this;
        }
        delete [] str;
        len = st.len;
        str = new char[len + 1];
        std::strcpy(str, st.str);
        return *this;
}

    // 将一个C字符串赋给一个字符串 assign a C string to a String
String & String::operator= (const char * s)
{
        delete [] str;
        len = std::strlen(s);
        str = new char[len + 1];
        std::strcpy(str, s);
        return *this;
}

    // 非const字符串的读写char访问 read-write char access for non-const String
char & String::operator[] (int i)
{
        return str[i];
}

    // Const String的只读字符访问 read-only char access for const String
const char & String::operator[] (int i) const
{
        return str[i];
}

// 重载的友元运算符 overloaded operator friends

bool operator< (const String & st1, const String & st2)
{
        return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator> (const String & st1, const String & st2)
{
        return st2 < st1;
}

bool operator== (const String & st1, const String & st2)
{
        return (std::strcmp(st1.str, st2.str) == 0);
}

    // 简单的字符串输出 simple String output
ostream & operator<< (ostream & os, const String & st)
{
        os << st.str;
        return os;
}

    // 快速和不干净的字符串输入 quick and dirty String input
istream & operator>> (istream & is, String & st)
{
        char temp[String::CINLIM];
        is.get(temp, String::CINLIM);
        if ( is )
        {
                st = temp;
        }
        while ( is && is.get() != '\n' )
        {
                continue;
        }
        return is;
}
