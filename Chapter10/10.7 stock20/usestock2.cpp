// usestck2.cpp -- using the Stock class
// compile with stock20.cpp
#include <iostream>
#include "stock20.h"
const int STKS = 4;
int main(void)
{
        // 创建一个初始化对象数组 create an array of initialized objects
        Stock stocks[STKS] = {
                Stock("NanoSmart", 12, 20.0),
                Stock("Boffo Objects", 200, 2.0),
                Stock("Monolithic Obelisks", 130, 3.25),
                Stock("Fleep Enterprises", 60, 6.5)
        };
        std::cout << "Stock holdings:\n";
        int st;
        for ( st = 0; st < STKS; st ++ )
        {
                stocks[st].show();
        }
        // 设置指向第一个元素的指针 set pointer to first element
        const Stock * top = &stocks[0];
        for ( st = 1; st < STKS; st ++ )
        {
                top = &top->topval(stocks[st]);
        }
        // 现在指向最有价值的控股 now top points to the most valuable holding
        std::cout << "\nMost valuable holding:\n";
        top->show();
        return 0;
}
