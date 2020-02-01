// twofile2.cpp -- variables with internal and external linkage
#include <iostream>
extern int tom; // tom别处定义 tom defined elsewhere
static int dick = 10; // 覆盖外部dick overrides external dick
int harry = 200; // 外部变量定义，与twofile1 harry无冲突 external variable definition, no conflict with twofile1 harry
void remote_access ()
{
        using namespace std;
        cout << "remote_access() reports the following addresses:\n";
        cout << &tom << " = &tom, " << &dick << " = &dick, ";
        cout << &harry << " = &harry\n";
}
