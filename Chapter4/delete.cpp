// delete.cpp -- using the delete operator
#include <iostream>
#include <cstring> // or string.h
using namespace std;
char * getname (void); // 函数原型 function prototype
int main(void)
{
        char * name; // 创建指针，但没有存储 create pointer but no storage
        name = getname(); // 将字符串地址分配给name assign address of string to name
        cout << name << " at " << (int *) name << "\n";
        delete [] name; // 内存释放 memory freed
        name = getname(); // 重用释放的内存 reuse freed memory
        cout << name << " at " << (int *) name << "\n";
        delete [] name; // 再次释放内存 memory freed again
        return 0;
}

char * getname (void) // 返回指向新字符串的指针 return pointer to new string
{
        char temp[80]; // 临时存储 temporary storage
        cout << "Enter last name: ";
        cin >> temp;
        char * pn = new char[strlen(temp) + 1];
        strcpy(pn, temp); // 将字符串复制到较小的空间 copy string into smaller space
        return pn; // 当函数结束时，temp丢失 temp lost when function ends
}
