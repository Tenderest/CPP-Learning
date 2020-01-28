// firstref.cpp -- defining and using a reference
#include <iostream>
int main(void)
{
        using namespace std;
        int rats = 101;
        int & rodents = rats; // rodents是一个引用 rodents is a reference
        cout << "rats = " << rats;
        cout << ", rodents = " << rodents << endl;
        rodents ++;
        cout << "rats = " << rats;
        cout << ", rodents = " << rodents << endl;
        // 一些实现需要类型转换以下地址以类型为unsigned
        // some implementations require type casting the following addresses to type unsigned
        cout << "rato addresses = " << &rats;
        cout << ", rodents addresses = " << &rodents << endl;
        return 0;
}
