// stonewt.h -- revised definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
        private:
                // 定义常量的两种方式
                // static const int Lbs_per_stn = 14;
                enum {Lbs_per_stn = 14}; // 磅每英石 pounds per stone
                int stone; // 整块英石 whole stone
                double pds_left; // 分数磅 fractional pounds
                double pounds; // 整磅重量 entire weight in pounds
        public:
                Stonewt(double lbs); // 双磅的构造函数 constructor for double pounds
                Stonewt(int stn, double lbs); // 英石，磅的构造函数 constructor for stone, lbs
                Stonewt(); // 默认构造函数 default constructor
                ~Stonewt();
                void show_lbs() const; // 以磅为单位显示重量 show weight in pounds format
                void show_stn() const; // 以英石单位显示重量 show weight in stone format
                // 转换函数 conversion functions
                operator int () const;
                operator double () const;
};

#endif
