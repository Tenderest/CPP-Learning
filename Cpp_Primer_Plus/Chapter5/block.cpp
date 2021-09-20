// block.cpp -- use a block statement
#include <iostream>
int main(void)
{
        using namespace std;
        cout << "The Amazing Accounto will sum and average ";
        cout << "five numbers for you.\n";
        cout << "Please enter five values: \n";
        double number;
        double sum = 0.0;
        for ( int i = 1; i <= 5; i ++ )
        {                                       // 块从这里开始 block starts here
                cout << "Value " << i << ": ";
                cin >> number;
                sum += number;
        }                                       // 块在这里结束 block ends here
        cout << "Five exquisite choices indeed: ";
        cout << "They sum to " << sum << endl;
        cout << "and average to " << sum / 5 << ".\n";
        cout << "The Amazing Accounto bids you adieu!\n";
        return 0;
}
