// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
        class Vector
        {
                public:
                        enum Mode {RECT, POL};
                        // 用于矩形的 RECT，用于极性模式的 POL RECT for rectangular, POL for Polar modes
                private:
                        double x; // 水平值 horizontal value
                        double y; // 垂直值 vertical value
                        double mag; // 矢量长度 向量的长度 length of vector
                        double ang; // 矢量的方向（以度表示） 向量方向（以度为单位） direction of vector in degrees
                        Mode mode; // RECT或POL RECT or POL
                        // 用于设置值的私有方法 private methods for setting values
                        void set_mag();
                        void set_ang();
                        void set_x();
                        void set_y();
                public:
                        Vector();
                        Vector (double n1, double n2, Mode form = RECT);
                        void reset (double n1, double n2, Mode form = RECT);
                        ~Vector();
                        double xval () const {return x;} // 报告x值 report x value
                        double yval () const {return y;} // 报告y值 report y value
                        double magval () const {return mag;} // 报告幅度 report magnitude
                        double angval () const {return ang;} // 报告角度 report angle
                        void polar_mode (); // 将模式设置为POL set mode to POL
                        void rect_mode (); // 将模式设置为RECT set mode to RECT
                        // 操作符重载 operator overloading
                        Vector operator+ (const Vector & b) const;
                        Vector operator- (const Vector & b) const;
                        Vector operator- () const;
                        Vector operator* (double n) const;
                        // 友元 friends
                        friend Vector operator* (double n, const Vector & a);
                        friend std::ostream & operator<< (std::ostream & os, const Vector & v);
        };
} // 结束名称空间VECTOR end namespace VECTOR

#endif
