// newstrct.cpp -- using new with a structure
#include <iostream>
struct inflatable // 结构定义 structure definition
{
        char name[20];
        float volume;
        double price;
};
int main(void)
{
        using namespace std;
        inflatable * ps = new inflatable; // 为结构分配内存 allot memery for structure
        cout << "Enter name of inflatable item: ";
        cin.get(ps->name, 20); // 成员访问的方法1 method 1 for member access
        cout << "Enter volume in cubic feet: ";
        cin >> (*ps).volume; // 成员访问的方法2 method 2 for member access
        cout << "Enter price: $";
        cin >> ps->price;
        cout << "Name: " << (*ps).name << endl; // 方法2 method 2
        cout << "Volume: " << ps->volume << " cubic feet\n"; // 方法1 method 1
        cout << "Price: $" << ps->price << endl; // 方法1 method 1
        delete ps; // 释放结构使用的内存 free memory used by structure
        return 0;
}
