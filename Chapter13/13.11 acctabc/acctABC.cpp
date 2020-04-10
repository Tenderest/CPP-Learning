// acctABC.cpp -- bank account class methods
#include <ios>
#include <iostream>
#include "acctabc.h"
using std::cout;
using std::endl;
using std::string;
using std::ios_base;

// 抽象基类 Abstract Base Class


AcctABC::AcctABC (const std::string & s, long an, double bal)
{
        fullName = s;
        acctNum = an;
        balance = bal;
}

void AcctABC::Deposit (double amt)
{
        if ( amt < 0 )
        {
                cout << "Negative deposit not allowed; deposit is cancelled.\n";
        }
        else
        {
                balance = amt;
        }
}

void AcctABC::Withdraw (double amt) // 纯虚函数 pure virtual function
{
        balance -= amt;
}

// 受保护的格式化方法 protected methods for formatting
AcctABC::Formatting AcctABC::SetFormat () const
{
        // 设置格式 #.##
        Formatting f;
        f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
        f.pr = cout.precision(2);
        return f;
}

void AcctABC::Restore (Formatting & f) const
{
        cout.setf(f.flag, ios_base::floatfield);
        cout.precision(f.pr);
}

// Brass方法 Brass methods
// Brass Account 类 Brass Account Class

void Brass::Withdraw (double amt)
{
        if ( amt < 0 )
        {
                cout << "Withdrawal amount must be positive; withdrawal canceled.\n";
        }
        else if( amt <= Balance() )
        {
                AcctABC::Withdraw(amt);
        }
        else
        {
                cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n" << "Withdrawal canceled.\n";
        }
}

void Brass::ViewAcct () const
{
        Formatting f = SetFormat();
        cout << "Brass Client: " << FullName() << endl;
        cout << "Account Number: " << AcctNum() << endl;
        cout << "Balance: $" << Balance() << endl;
        Restore(f); // 恢复原始格式 restore original format
}

// BrassPlus Methods
// Brass Plus Account Class
BrassPlus::BrassPlus (const string & s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
        maxLoan  = ml;
        owesBank = 0.0;
        rate     = r;
}

BrassPlus::BrassPlus (const Brass & ba, double ml, double r) : AcctABC(ba) // 使用隐式复制构造函数 use implicit copy constructor
{
        maxLoan  = ml;
        owesBank = 0.0;
        rate     = r;
}

// 重新定义ViewAcct()的工作方式 redefine how ViewAcct() works
void BrassPlus::ViewAcct () const
{
        Formatting f = SetFormat();

        cout << "BrassPlus Client: " << FullName() << endl;
        cout << "Account Number: " << AcctNum() << endl;
        cout << "Balance: $" << Balance() << endl;
        cout << "Maximum loan: $" << maxLoan << endl;
        cout << "Owed to bank: $" << owesBank << endl;
        cout.precision(3);
        cout << "Loan Rate: " << 100 * rate << "%\n";
        Restore(f); // 恢复原始格式 restore original format
}

// 重新定义Withdraw()的工作方式 redefine how Withdraw() works
void BrassPlus::Withdraw (double amt)
{
        Formatting f = SetFormat();

        double bal = Balance();
        if ( amt <= bal )
        {
                AcctABC::Withdraw(amt);
        }
        else if ( amt <= bal + maxLoan - owesBank )
        {
                double advance = amt - bal;
                owesBank += advance * (1.0 + rate);
                cout << "Bank advance: $" << advance << endl;
                cout << "Finance charge: $" << advance * rate << endl;
                Deposit(advance);
                AcctABC::Withdraw(amt);
        }
        else
        {
                cout << "Credit limit exceeded. Transaction cancelled.\n";
        }
        Restore(f); // 恢复原始格式 restore original format
}
