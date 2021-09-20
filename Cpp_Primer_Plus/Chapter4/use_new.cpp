// use_new.cpp -- using the new operator
#include <iostream>
int main(void)
{
        using namespace std;
        int nights = 1001;
        int * pt = new int; // 为int分配空间 allocate space for an int
        *pt = 1001; // 在那里存储一个值 store a value there
        cout << "nights value = ";
        cout << nights << ": location " << &nights << endl;
        cout << "int ";
        cout << "value = " << *pt << ": location = " << pt << endl;
        double * pd = new double; // 为double分配空间 allocate space for an double
        *pd = 10000001.0; // 在那里存储一个double store a double there
        cout << "double ";
        cout << "value = " << *pd << ": location = " << pd << endl;
        cout << "location of pointer pd: " << &pd << endl;
        cout << "size of pt = " << sizeof(pt);
        cout << ": size of *pt = " << sizeof(*pt) << endl;
        cout << "size of pd = " << sizeof(pd);
        cout << ": size of *pd = " << sizeof(*pd) << endl;
        return 0;
}
