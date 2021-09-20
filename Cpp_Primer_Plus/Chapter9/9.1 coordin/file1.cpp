// file1.cpp -- example of a three-file program
#include <iostream>
#include "coordin.h" // 结构模板、函数原型 structure templates, function prototypes
using namespace std;
int main(void)
{
        rect rplace;
        polar pplace;
        cout << "Enter the x and y values: ";
        while ( cin >> rplace.x >> rplace.y ) // cin的巧妙使用 slick use of cin
        {
                pplace = rect_to_polar(rplace);
                show_polar(pplace);
                cout << "Next two numbers (q to quit): ";
        }
        cout << "Bye.\n";
        return 0;
}
