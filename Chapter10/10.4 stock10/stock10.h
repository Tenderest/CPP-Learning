// stock10.h -- Stock class declaration with constructors, destructor added
#ifndef STOCK10_H_
#define STOCK10_H_

#include <string>
class Stock // 类声明 class diclaration
{
private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }
public:
// 两个构造函数 two constructors
        Stock(); // 默认构造函数 default constructor
        Stock (const std::string & co, long n = 0, double pr = 0.0);
        ~Stock(); // 嘈杂的析构函数 noisy destructor
        void buy (long num, double price);
        void sell (long num, double price);
        void update (double price);
        void show ();
}; // 注意末尾的分号 note semicolon at the end

#endif
