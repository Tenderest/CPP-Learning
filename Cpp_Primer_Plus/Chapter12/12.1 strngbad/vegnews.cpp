// vegnews.cpp -- using new and delete with classes
// compile with strngbad.cpp
#include <iostream>
using std::cout;
#include "strngbad.h"

void callme1 (StringBad &); // 通过引用 pass by reference
void callme2 (StringBad); // 按值传递 pass by value

int main(void)
{
        using std::endl;
        {
                cout << "Starting an inner block.\n";
                StringBad headline1("Celery Stalks at Midnight");
                StringBad headline2("Lettuce Prey");
                StringBad sports("Spinach Leaves Bowl for Dollars");
                cout << "headline1: " << headline1 << endl;
                cout << "headline2: " << headline2 << endl;
                cout << "sports: " << sports << endl;
                callme1(headline1);
                cout << "headline1: " << headline1 << endl;
                callme2(headline2);
                cout << "headline2: " << headline2 << endl;
                cout << "Initialize one object to another:\n";
                StringBad sailor = sports;
                cout << "sailor: " << sailor << endl;
                cout << "Assign one object to another:\n";
                StringBad knot;
                knot = headline1;
                cout << "knot: " << knot << endl;
                cout << "Exting the block.\n";
        }
        cout << "End of main()\n";
        return 0;
}

void callme1 (StringBad & rsb) // 通过引用 pass by reference
{
        cout << "String passed by reference:\n";
        cout << "    \"" << rsb << "\"\n";
}
void callme2 (StringBad sb) // 按值传递 pass by value
{
        cout << "String passed by value:\n";
        cout << "    \"" << sb << "\"\n";
}
