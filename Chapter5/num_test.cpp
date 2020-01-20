// num_test.cpp -- use numeric test in for loop
#include <iostream>
int main(void)
{
        using namespace std;
        cout << "Enter the starting countdown value: ";
        int limit;
        cin >> limit;
        int i;
        for ( i = limit; i; i -- ) // 当i = 0时退出 quits when i is 0
        {
                cout << "i = " << i << "\n";
        }
        cout << "Done now that i = " << i << "\n";
        return 0;
}
