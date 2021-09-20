// dma.cpp -- dma class methods

#include "dma.h"
#include <cstring>

// 使用DMA的基类 Base Class Using DMA
// DMA = dynamic memory allocation
// baseDMA 方法 baseDMA methods
baseDMA::baseDMA (const char * l, int r)
{
        label = new char[std::strlen(l) + 1];
        std::strcpy(label, l);
        rating = r;
}

baseDMA::baseDMA (const baseDMA & rs) // 复制构造函数
{
        label = new char[std::strlen(rs.label) + 1];
        std::strcpy(label, rs.label);
        rating = rs.rating;
}

baseDMA::~baseDMA()
{
        delete [] label; // 必须手动删除用new分配的空间
}

baseDMA & baseDMA::operator= (const baseDMA & rs)
{
        if ( this == &rs )
        {
                return *this;
        }
        delete [] label;
        label = new char[std::strlen(rs.label) + 1];
        std::strcpy(label, rs.label);
        rating = rs.rating;
        return *this;
}

std::ostream & operator<< (std::ostream & os, const baseDMA & rs)
{
        os << "Label: " << rs.label << std::endl;
        os << "Rating: " << rs.rating << std::endl;
        return os;
}

// lacksDMA 方法 lacksDMA methods
// 没有DMA的派生类      derived class without DMA
// 不需要析构函数       no destructor needed
// 使用隐式副本构造函数 uses implicit copy constructor
// 使用隐式赋值运算符   uses implicit assignment operator
lacksDMA::lacksDMA (const char * c, const char * l, int r) : baseDMA(l, r)
{
        std::strncpy(color, c, 39);
        color[39] = '\0';
}

lacksDMA::lacksDMA (const char * c, const baseDMA & rs) : baseDMA(rs)
{
        std::strncpy(color, c, COL_LEN - 1);
        color[COL_LEN - 1] = '\0';
}

std::ostream & operator<< (std::ostream & os, const lacksDMA & ls)
{
        os << (const baseDMA &) ls; // 强制类型转换，变成基类的引用，使用基类的友元函数
        os << "Color: " << ls.color << std::endl;
        return os;
}

// hasDMA 方法 hasDMA methods
// 带有DMA的派生类 derived class with DMA
hasDMA::hasDMA (const char * s, const char * l, int r) : baseDMA(l, r)
{
        style = new char[std::strlen(s) + 1];
        std::strcpy(style, s);
}

hasDMA::hasDMA (const char * s, const baseDMA & rs) : baseDMA(rs)
{
        style = new char[std::strlen(s) + 1];
        std::strcpy(style, s);
}

// 复制构造函数
hasDMA::hasDMA (const hasDMA & hs) : baseDMA(hs) // 调用基类复制构造函数 invoke base class copy constructor
{
        style = new char[std::strlen(hs.style) + 1];
        std::strcpy(style, hs.style);
}
hasDMA::~hasDMA ()
{
        delete [] style; // 必须手动删除用new分配的空间
}
hasDMA & hasDMA::operator= (const hasDMA & hs) // 赋值运算符
{
        if ( this == &hs )
        {
                return *this;
        }
        baseDMA::operator=(hs);
        delete [] style;
        style = new char[std::strlen(hs.style) + 1]; // 复制基础部分 copy base portion
        std::strcpy(style, hs.style);                // 为新style做准备 prepare for new style
        return *this;
}
std::ostream & operator<< (std::ostream & os, const hasDMA & hs)
{
        os << (const baseDMA &) hs; // 强制类型转换，变成基类的引用，使用基类的友元函数
        os << "Style: " << hs.style << std::endl;
        return os;
}
