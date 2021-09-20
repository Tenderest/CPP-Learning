// not.cpp -- using the not operator
#include <iostream>
#include <climits>
bool is_int (double );
int main(void)
{
        using namespace std;
        double num;
        cout << "Yo, dude! Enter an integer value: ";
        cin >> num;
        while ( ! is_int(num) ) // num不可整数时继续 continue while num is not int-able
        {
                cout << "Out of range -- please try again: ";
                cin >> num;
        }
        int val = int (num); // 类型转换 type cast
        cout << "You've entered the integer " << val << "\nBye\n";
        return 0;
}
bool is_int (double x)
{
        if ( x <= INT_MAX && x >= INT_MIN ) // 使用climits值 use climits value
        {
                return true;
        }
        else
        {
                return false;
        }
}
