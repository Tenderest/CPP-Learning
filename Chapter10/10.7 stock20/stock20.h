// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_

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
        Stock(); // 默认构造函数 default constructor
        Stock (const std::string & co, long n = 0, double pr = 0.0);
        ~Stock(); // 不做事的析构函数 do-nothing destructor
        void buy (long num, double price);
        void sell (long num, double price);
        void update (double price);
        void show () const;
        const Stock & topval (const Stock & s) const;
}; // 注意末尾的分号 note semicolon at the end

#endif
