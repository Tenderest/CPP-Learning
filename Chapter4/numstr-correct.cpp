// numstr.cpp -- following number input with line input
#include <iostream>
int main(void)
{
        using namespace std;
        cout << "What year was your house built?\n";
        int year;
        /* Correct */
        /* 1 */
        cin >> year;
        cin.get(); // or cin.get(ch);
        /* 2 */
        (cin >> year).get(); // or (cin >> year).get(ch);
        cout << "What is its street address?\n";
        char address[80];
        cin.getline(address, 80);
        cout << "Year built: " << year << endl;
        cout << "Address: " << address << endl;
        cout << "Done!\n";
        return 0;
}
