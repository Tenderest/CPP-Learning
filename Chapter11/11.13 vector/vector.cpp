// vector.cpp -- methods for the Vector class
#include <cmath>
#include "vector.h" // includes <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
        // 计算一个弧度的度数 compute degrees in one radian
        const double Rad_to_deg = 45.0 / atan(1.0);
        // 应该是57.2957795130823左右 should be about 57.2957795130823
        
        // 私有方法 private methods
        // 根据x和y计算幅度 calculates magnitude from x and y
        void Vector::set_mag()
        {
                mag = sqrt(x * x + y * y);
        }
        void Vector::set_ang()
        {
                if ( x == 0.0 && y == 0.0 )
                {
                        ang = 0.0;
                }
                else
                {
                        ang = atan2(y, x);
                }
        }
        
        // 从极坐标设置x set x from polar coordinate
        void Vector::set_x()
        {
                x = mag * cos(ang);
        }

        // 从极坐标设置y set y from polor coordinate
        void Vector::set_y()
        {
                y = mag * sin(ang);
        }

        // 公共方法 public methods
        Vector::Vector() // 默认构造函数 default constructor
        {
                x = y = mag = ang = 0.0;
                mode = RECT;
        }

        // 如果形式为r，则从直角坐标构造向量 construct vector from rectangular coordinates if form is r
        // （默认值），或者如果形式为p，则从极坐标 or else from polar coordinates if form is p
        Vector::Vector (double n1, double n2, Mode form)
        {
                mode = form;
                if ( form = RECT )
                {
                        x = n1;
                        y = n2;
                        set_mag();
                        set_ang();
                }
                else if( form = POL )
                {
                        mag = n1;
                        ang = n2 / Rad_to_deg;
                        set_x();
                        set_y();
                }
                else
                {
                        cout << "Incorrect 3rd argument to Vector() -- ";
                        cout << "vector set to 0\n";
                        x = y = mag = ang = 0.0;
                        mode = RECT;
                }
        }

        // 如果形式是ReCT（默认值），则从直角坐标重置向量，如果形式是POL，则从极坐标重置向量
        // reset Vector from rectangular coordinates if form is RECT (the default) or else from polar coordinates if form is POL
        void Vector::reset (double n1, double n2, Mode form)
        {
                mode = form;
                if ( form == RECT )
                {
                        x = n1;
                        y = n2;
                        set_mag();
                        set_ang();
                }
                else if( form == POL )
                {
                        mag = n1;
                        ang = n2 / Rad_to_deg;
                        set_x();
                        set_y();
                }
                else
                {
                        cout << "Incorrect 3rd argument to Vector() --";
                        cout << "vector set to 0\n";
                        x = y = mag = ang = 0.0;
                        mode = RECT;
                }
        }

        Vector::~Vector() // 析构函数 destructor
        {

        }

        void Vector::polar_mode () // 设置为极坐标模式 set to polar mode
        {
                mode = POL;
        }

        void Vector::rect_mode () // 设置为直角坐标模式 set to rectangular mode
        {
                mode = RECT;
        }
        
        // 操作符重载 operator overloading
        // 两个向量相加 add two Vectors
        Vector Vector::operator+ (const Vector & b) const
        {
                return Vector(x + b.x, y + b.y);
        }

        // 从a中减去向量b subtract Vector b from a
        Vector Vector::operator- (const Vector & b) const
        {
                return Vector(x - b.x, y - b.y);
        }

        // 向量的反符号 reverse sign of Vector
        Vector Vector::operator- () const
        {
                return Vector(-x, -y);
        }

        // 将向量乘以n multiply
        Vector Vector::operator* (double n) const
        {
                return Vector(n * x, n * y);
        }

        // 友元方法 friend methods
        // 用n乘以向量a mutiply n by Vector a
        Vector operator* (double n, const Vector & a)
        {
                return a * n;
        }

        // 如果模式是RECT，则显示直角坐标;如果模式是POL，则显示极坐标
        // display rectangular coordinates if mode is RECT, else display polar coordinates if mode is POL
        std::ostream & operator<< (std::ostream & os, const Vector & v)
        {
                if ( v.mode == Vector::RECT )
                {
                        os << "(x,y) = (" << v.x << ", " << v.y << ")";
                }
                else if ( v.mode == Vector::POL )
                {
                        os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
                }
                else
                {
                        os << "Vector object mode is invalid";
                }
                return os;
        }
} // 结束名称空间VECTOR end namespace VECTOR
