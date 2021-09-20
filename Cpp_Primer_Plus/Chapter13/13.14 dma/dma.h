// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>
#include <ostream>

// 使用DMA的基类 Base Class Using DMA
// DMA = dynamic memory allocation
class baseDMA
{
        private:
                char * label;
                int rating;
        public:
                baseDMA (const char * l = "null", int r = 0);
                baseDMA (const baseDMA & rs);
                virtual ~baseDMA();
                baseDMA & operator= (const baseDMA & rs);
                friend std::ostream & operator<< (std::ostream & os, const baseDMA & rs);
};

// 没有DMA的派生类      derived class without DMA
// 不需要析构函数       no destructor needed
// 使用隐式副本构造函数 uses implicit copy constructor
// 使用隐式赋值运算符   uses implicit assignment operator
class lacksDMA : public baseDMA
{
        private:
                enum { COL_LEN = 40 };
                char color[COL_LEN];
        public:
                lacksDMA (const char * c = "blank", const char * l = "null", int r = 0);
                lacksDMA (const char * c, const baseDMA & rs);
                friend std::ostream & operator<< (std::ostream & os, const lacksDMA & rs);
};

// 带有DMA的派生类 derived class with DMA
class hasDMA : public baseDMA
{
        private:
                char * style;
        public:
                hasDMA (const char * s = "none", const char * l = "null", int r = 0);
                hasDMA (const char * s, const baseDMA & rs);
                hasDMA (const hasDMA & rs); // 复制构造函数
                ~hasDMA ();
                hasDMA & operator= (const hasDMA & rs); // 赋值运算符
                friend std::ostream & operator<< (std::ostream & os, const hasDMA & rs);
};

#endif
