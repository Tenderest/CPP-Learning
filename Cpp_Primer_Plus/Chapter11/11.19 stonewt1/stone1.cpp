// stone1.cpp -- user-defined conversions functions
// compile with stonewt1.cpp
#include <iostream>
using std::cout;
#include "stonewt1.h"

int main(void)
{
        Stonewt poppins(9,2.8); // 9英石，2.8磅 9 stone, 2.8 pounds
        double p_wt = poppins; // 隐式转换 implicit conversion
        cout << "Convert to double => ";
        cout << "Poppins: " << p_wt << " pounds.\n";
        cout << "Convert to int => ";
        cout << "Poppins: " << int(poppins) << " pounds.\n";
        return 0;
}
