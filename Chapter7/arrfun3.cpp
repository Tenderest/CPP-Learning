// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;
// 函数原型 function prototypes
int fill_array (double ar[], int limit);
void show_array (const double ar[], int n); // 不要更改数据 don't change data
void revalue (double r, double ar[], int n);
int main(void)
{
        using namespace std;
        double properties[Max];
        int size = fill_array(properties, Max);
        show_array(properties, size);
        if ( size > 0 )
        {
                cout << "Enter revaluation factor: ";
                double factor;
                while ( !(cin >> factor) ) // 输入错误 bad input
                {
                        cin.clear();
                        while ( cin.get() != '\n' )
                        {
                                continue;
                        }
                        cout << "Bad input; Please enter a number: ";
                }
                revalue(factor, properties, size);
                show_array(properties, size);
        }
        cout << "Done.\n";
        cin.get();
        cin.get();
        return 0;
}
int fill_array (double ar[], int limit)
{
        using namespace std;
        double temp;
        int i;
        for ( i = 0; i < limit; i ++ )
        {
                cout << "Enter value #" << (i + 1) << ": ";
                cin >> temp;
                if ( !cin ) // 输入错误 bad input
                {
                        cin.clear();
                        while ( cin.get() != '\n' )
                        {
                                continue;
                        }
                        cout << "Bad input; input process terminated.\n";
                        break;
                }
                else if ( temp < 0 ) // 终止信号 signal to terminate
                {
                        break;
                }
                ar[i] = temp;
        }
        return i;
}
// 下面的函数可以使用地址为ar的数组，但不能改变它
// the following function can use, but not alter, the array whose address is ar
void show_array (const double ar[], int n)
{
        using namespace std;
        for ( int i = 0; i < n; i ++ )
        {
                cout << "Property #" << (i + 1) << ": $";
                cout << ar[i] << endl;
        }
}
// 将ar []的每个元素乘以r
// multiplies each element of ar[] by r
void revalue (double r, double ar[], int n)
{
        for ( int i = 0; i < n; i ++ )
        {
                ar[i] *= r;
        }
}
