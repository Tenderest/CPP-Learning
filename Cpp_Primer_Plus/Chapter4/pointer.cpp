// pointer.cpp -- our first pointer variable
#include <iostream>
int main(void)
{
        using namespace std;
        int updates = 6; // 声明一个变量 declare a variable
        int * p_updates; // 声明一个指向整型数的指针 declare pointer to an int
        p_updates = &updates; // 为指针分配int地址 assign address of int to pointer
        // 两种表达值的方式 express values two ways
        cout << "Values: updates = " << updates;
        cout << ", *p_updates = " << *p_updates << endl;
        // 两种表达地址的方式 express address two ways
        cout << "Addresses: &updates = " << &updates;
        cout << ", p_updates = " << p_updates << endl;
        // 使用指针更改值 use pointer to change value
        *p_updates = *p_updates + 1;
        cout << "Now updates = " << updates << endl;
        return 0;
}
