// brass.cpp -- bank account class methods
#include <ios>
#include <iostream>
#include <iterator>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

// 格式化内容 formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat ();
void restore (format f, precis p);

// Brass方法 Brass methods
// Brass Account 类 Brass Account Class
Brass::Brass (const std::string & s , long an , double bal)
{
        fullName = s;
        acctNum = an;
        balance = bal;
}

void Brass::Deposit (double amt)
{
        if ( amt < 0 )
        {
                cout << "Negative deposit not allowed; deposit is cancelled.\n";
        }
        else
        {
                balance += amt;
        }
}

void Brass::Withdraw (double amt)
{
        // 设置###.##格式 set up ###.## format
        format initialState = setFormat();
        precis prec = cout.precision(2);

        if ( amt < 0 )
        {
                cout << "Withdrawal amount must be positive; withdrawal canceled.\n";
        }
        else if ( amt <= balance )
        {
                balance -= amt;
        }
        else
        {
                cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n"
                     << "Withdrawal canceled.\n";
        }
        restore(initialState, prec);
}

double Brass::Balance () const
{
        return balance;
}

void Brass::ViewAcct () const
{
        // 设置###.##格式 set up ###.## format
        format initialState = setFormat();
        precis prec = cout.precision(2);
        cout << "Client: " << fullName << endl;
        cout << "Account Number: " << acctNum << endl;
        cout << "Balance: $" << balance << endl;
        restore(initialState, prec); // 恢复原始格式 restore original format
}

// BrassPlus Methods
// Brass Plus Account Class
BrassPlus::BrassPlus (const std::string & s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
        maxLoan  = ml;
        owesBank = 0.0;
        rate     = r;
}

BrassPlus::BrassPlus (const Brass & ba, double ml, double r) : Brass(ba) // 使用隐式复制构造函数 use implicit copy constructor
{
        maxLoan  = ml;
        owesBank = 0.0;
        rate     = r;
}

// 重新定义ViewAcct()的工作方式 redefine how ViewAcct() works
void BrassPlus::ViewAcct () const
{
        // 设置###.##格式 set up ###.## format
        format initialState = setFormat();
        precis prec = cout.precision(2);

        Brass::ViewAcct(); // 显示基础部分 display base portion
        cout << "Maximum loan: $" << maxLoan << endl;
        cout << "Owed to bank: $" << owesBank << endl;
        cout.precision(3);
        cout << "Loan Rate: " << 100 * rate << "%\n";
        restore(initialState, prec); // 恢复原始格式 restore original format
}

// 重新定义Withdraw()的工作方式 redefine how Withdraw() works
void BrassPlus::Withdraw (double amt)
{
        // 设置###.##格式 set up ###.## format
        format initialState = setFormat();
        precis prec = cout.precision(2);

        double bal = Balance();
        if ( amt <= bal )
        {
                Brass::Withdraw(amt);
        }
        else if ( amt <= bal + maxLoan - owesBank )
        {
                double advance = amt - bal;
                owesBank += advance * (1.0 + rate);
                cout << "Bank advance: $" << advance << endl;
                cout << "Finance charge: $" << advance * rate << endl;
                Deposit(advance);
                Brass::Withdraw(amt);
        }
        else
        {
                cout << "Credit limit exceeded. Transaction cancelled.\n";
        }
        restore(initialState, prec); // 恢复原始格式 restore original format
}

format setFormat ()
{
        // 设置###.##格式 set up ###.## format
        return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore (format f, precis p)
{
        cout.setf(f, std::ios_base::floatfield);
        cout.precision(p);
}
