// string1.h -- fixed and augmented string class definition
#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
#include <istream>
#include <ostream>

using std::ostream;
using std::istream;

class String
{
        private:
                char * str;                   // 指向字符串的指针 pointer to string
                int len;                      // 字符串长度 length of string
                static int num_strings;       // 对象数 num of objects
                static const int CINLIM = 80; // cin输入限制 cin input limit
        public:
                // 构造函数和其他方法 constructor and other methods
                String (const char * s); // 构造函数 constructor
                String (); // 默认构造函数 default constructor
                String (const String & ); // 复制构造函数 copy constructor
                ~String(); // 析构函数 destructor
                int length () const { return len; }
                // 重载运算符方法 overloaded operator methods
                String & operator= (const String & );
                String & operator= (const char * );
                char & operator[] (int i);
                const char & operator[] (int i) const;
                // 重载的友元运算符 overloaded operator friends
                friend bool operator< (const String &st, const String &s2);
                friend bool operator> (const String &s1, const String &s2);
                friend bool operator== (const String &st, const String &s2);
                friend ostream & operator<< (ostream & os, const String & st);
                friend istream & operator>> (istream & is, String & st);
                // 静态函数 static function
                static int Howmany ();
};

#endif
