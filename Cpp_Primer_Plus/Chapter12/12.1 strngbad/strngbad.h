// strngbad.h -- flawed string class definition
#include <iostream>
#include <ostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
        private:
                char * str; // 指向字符串的指针 pointer string
                int len; // 字符串长度 lenth of string
                static int num_strings; // 对象数 number of objects
        public:
                StringBad (const char * s); // 构造函数 constructor
                StringBad (); // 默认构造函数 default contructor
                ~StringBad (); // 析构函数 destructor
                // 友元函数 friend function
                friend std::ostream & operator<< (std::ostream & os, const StringBad & st);
};

#endif
