// twofile1.cpp -- variables with external and internal linkage
#include <iostream> // 用twofile2.cpp编译 to be compiled with two file2.cpp
int tom = 3; // 外部变量定义 external variable definition
int dick = 30; // 外部变量定义 external variable definition
static int harry = 300; // 静态内部链接 static, internal linkage
// 函数原型 function prototype
void remote_access ();
int main(void)
{
        using namespace std;
        cout << "main() reports the following addresses:\n";
        cout << &tom << " = &tom, " << &dick << " = &dick, ";
        cout << &harry << " = &harry\n";
        remote_access();
        return 0;
}

