// stonewt.cpp -- Stonewt class methods + conversion functions
#include <iostream>
#include "stonewt1.h"
using std::cout;

// double值的构造函数Stonewt对象 construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
        stone = int (lbs) / Lbs_per_stn; // 整数除法 integer division
        pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
        pounds = lbs;
}

// 构造函数Stonewt对象来自stone，double值 construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
        stone = stn;
        pds_left = lbs;
        pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt() // 默认构造函数，wt = 0
{
        stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() // 析构函数 destructor
{

}

// 以英石为单位显示重量 show weight in stones
void Stonewt::show_stn() const
{
        cout << stone << " stone, " << pds_left << " pounds\n";
}

// 以磅为单位显示重量 show weight in pounds
void Stonewt::show_lbs() const
{
        cout << pounds << " pounds\n";
}

// 转换函数 conversion functions
Stonewt::operator int () const
{
        return int (pounds + 0.5);
}

Stonewt::operator double () const
{
        return pounds;
}
