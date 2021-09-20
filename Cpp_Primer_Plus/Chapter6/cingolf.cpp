// cingolf.cpp -- non-numeric input skipped
#include <iostream>
const int Max = 5;
int main(void)
{
        using namespace std;
        // 获取数据 get data
        int golf[Max];
        cout << "Please enter your golf scores.\n";
        cout << "You must enter " << Max << " rounds.\n";
        int i;
        for ( i = 0; i < Max; i ++ )
        {
                cout << "round #" << i + 1 << ": ";
                while ( !(cin >> golf[i]) )
                {
                        cin.clear(); // 重置输入 reset input
                        while ( cin.get() != '\n' )
                        {
                                continue; // 摆脱错误的输入 get rid of bad input
                        }
                        cout << "Please enter a number: ";
                }
        }
        // 计算平均值 calculate average
        double total = 0.0;
        for ( i = 0; i < Max; i ++ )
        {
                total += golf[i];
        }
        // 报告结果 report results
        cout << total / Max << " = avergae score " << Max << " rounds\n";
        return 0;
}
