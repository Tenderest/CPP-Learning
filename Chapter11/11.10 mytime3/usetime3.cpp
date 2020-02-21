// usetime3.cpp -- using the fourth draft of the Time class
// complie usetime3.cpp and mytime3.cpp together
#include <iostream>
#include "mytime3.h"

int main(void)
{
        using std::cout;
        using std::endl;
        Time aida(3, 35);
        Time tosca(2, 48);
        Time temp;

        cout << "Aida and Tosca:\n";
        cout << aida << "; " << tosca << endl;
        temp = aida + tosca; // operator+ ()
        cout << "Aida + Tosca: " << temp << endl;
        temp = aida * 1.17; // 成员运算符*() member operator* ()
        cout << "Aida * 1.17: " << temp << endl;
        cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

        return 0;
}
