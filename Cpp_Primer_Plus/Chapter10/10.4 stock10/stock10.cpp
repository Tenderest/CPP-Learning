// stock10.cpp -- Stock class with constructors, destructor added
#include <iostream>
#include "stock10.h"
// 构造函数（详细版本） constructors (verbose versions)
Stock::Stock() // 默认构造函数 default constructor
{
        std::cout << "Default constructor called\n";
        company = "no name";
        shares = 0;
        share_val = 0.0;
        total_val = 0.0;
}
Stock::Stock (const std::string & co, long n, double pr)
{
        std::cout << "Constructor using " << co << " called\n";
        company = co;
        if ( n < 0 )
        {
                std::cout << "Number of shares can't be negative; "
                          << company << " shares set to 0.\n";
                shares = 0;
        }
        else
        {
                shares = n;
        }
        share_val = pr;
        set_tot();
}
// 类析构函数 class destructor
Stock::~Stock() // 详细的类析构函数 verbose class destructor
{
        std::cout << "Bye, " << company << "!\n";
}
// 其他方法 other methods
void Stock::buy (long num, double price)
{
        if ( num < 0 )
        {
                std::cout << "Number of shares purchased can't be negative. "
                     << "Transaction in aborted.\n";
        }
        else
        {
                shares += num;
                share_val = price;
                set_tot();
        }
}
void Stock::sell (long num, double price)
{
        using std::cout;
        if ( num < 0 )
        {
                cout << "Number of shares sold can't be nagative. "
                     << "Transaction is aborted.\n";
        }
        else if ( num > shares )
        {
                cout << "You can't sell more than you have! "
                     << "Transaction is aborted.\n";
        }
        else
        {
                shares -= num;
                share_val = price;
                set_tot();
        }
}
void Stock::update (double price)
{
        share_val = price;
        set_tot();
}
void Stock::show ()
{
        using std::cout;
        using std::ios_base;
        // 将格式设置为#.### set format to #.###
        ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
        std::streamsize prec = cout.precision(3);

        cout << "Company: " << company
             << "  Shares: " << shares << '\n';
        cout << "  Share Price: $" << share_val;
        // 设置格式#.## set format #.##
        cout.precision(2);
        cout << "  Total Worth: $" << total_val << '\n';
        // 恢复原始格式 restore original format
        cout.setf(orig, ios_base::floatfield);
        cout.precision(prec);
}
