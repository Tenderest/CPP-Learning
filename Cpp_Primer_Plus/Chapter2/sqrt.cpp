// sqrt.cpp -- using the sqrt() function
#include <iostream>
#include <cmath> // 老式编译器应使用math.h 并在编译时使用 -lm 选项
int main(void)
{
        using namespace std;
        double area;
        cout << "Enter the floor area, in square feet, of your home: ";
        cin >> area;
        double side;
        side = sqrt(area);
        cout << "That's the equivalent of a square " << side
             << " feet to the side." << endl;
        cout << "How fascinating!" << endl;
        return 0;
}
