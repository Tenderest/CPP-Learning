// acctabc.h -- bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <ios>
#include <iostream>
#include <string>

// 抽象基类 Abstract Base Class
class AcctABC
{
        private:
                std::string fullName;
                long acctNum;
                double balance;
        protected:
                struct Formatting
                {
                        std::ios_base::fmtflags flag;
                        std::streamsize pr;
                };
                const std::string & FullName () const {return fullName;}
                long AcctNum () const {return acctNum;}
                Formatting SetFormat () const;
                void Restore (Formatting & f) const;
        public:
                AcctABC (const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
                void Deposit (double amt);
                virtual void Withdraw (double amt) = 0; // 纯虚函数 pure virtual function
                double Balance () const {return balance;};
                virtual void ViewAcct () const = 0; // 纯虚函数 pure virtual function
                virtual ~AcctABC () {}
};

// Brass Account 类 Brass Account Class
class Brass : public AcctABC
{
        public:
            Brass (const std::string & s = "Nullbody", long an = -1, double bal = 0.0)
                    : AcctABC(s, an, bal) { }
            virtual void Withdraw (double amt);
            virtual void ViewAcct () const;
            virtual ~Brass () {}
};

// Brass Plus 账户类 Brass Plus Account Class
class BrassPlus : public AcctABC
{
        private:
                double maxLoan;
                double rate;
                double owesBank;
        public:
                BrassPlus (const std::string & s = "Nullbody", long an = -1, double bal = 0.0,
                                double ml = 500, double r = 0.10);
                BrassPlus (const Brass & ba, double ml = 500, double r = 0.1);
                virtual void ViewAcct () const;
                virtual void Withdraw (double amt);
                void ResetMax (double m) { maxLoan = m; }
                void ResetRate (double r) { rate = r; };
                /* void ResetRate (double r) { rate = r; } */
                void Resetowes () { owesBank = 0; }
}; 

#endif
