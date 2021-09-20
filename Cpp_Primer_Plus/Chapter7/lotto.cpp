// lotto.cpp -- probability of winning
#include <iostream>
// 注意：某些实现需要double而不是long double NOTE: some implementations require double instead of long double
long double probability (unsigned numbers, unsigned picks);
int main(void)
{
        using namespace std;
        double total, choices;
        cout << "Enter the total number of choices on the game card and\n"
                "the number of picks allowed:\n";
        while ( (cin >> total >> choices) && choices <= total )
        {
                cout << "You have one chance in ";
                cout << probability(total, choices); // 计算赔率 compute the odds
                cout << " of winning.\n";
                cout << "Next two numbers (q to quit): ";
        }
        cout << "bye\n";
        return 0;
}
// 下面的函数计算从号码选择中正确选择号码的概率
// the following function calculates the probability of picking picks numbers correctly from numbers choices
long double probability (unsigned numbers, unsigned picks)
{
        long double result = 1.0; // 这是一些局部变量 here come some local variables
        long double n;
        unsigned p;
        for ( n = numbers, p = picks; p > 0; n --, p -- )
        {
                result = result * n / p;
        }
        return result;
}
