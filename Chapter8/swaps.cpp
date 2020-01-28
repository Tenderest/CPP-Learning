// swaps.cpp -- swapping with references and with pointers
#include <iostream>
void swapr (int & a, int & b); // a b是int的别名 a, b are aliases for ints
void swapp (int * a, int * b); // a b是整数的地址 a, b are addresses of ints
void swapv (int a, int b); // a b是新变量 a, b are new variables
int main(void)
{
        using namespace std;
        int wallet1 = 300;
        int wallet2 = 350;
        cout << "wallet1 = $" << wallet1;
        cout << " wallet2 = $" << wallet2 << endl;
        cout << "Using references to swap contents:\n";
        swapr(wallet1, wallet2); // 传递变量 pass variables
        cout << "wallet1 = $" << wallet1;
        cout << " wallet2 = $" << wallet2 << endl;
        cout << "Using pointers to swap contents again:\n";
        swapp(&wallet1, &wallet2); // 传递变量地址 pass addresses of variables
        cout << "wallet1 = $" << wallet1;
        cout << " wallet2 = $" << wallet2 << endl;
        cout << "Trying to use passing by value:\n";
        swapv(wallet1, wallet2); // 传递变量值 
        cout << "wallet1 = $" << wallet1;
        cout << " wallet2 = $" << wallet2 << endl;
        return 0;
}
void swapr (int & a, int & b) // 使用引用 use references
{
        int temp;
        temp = a; // 使用a，b表示变量值 use a, b for values of variables
        a = b;
        b = temp;
}
void swapp (int * p, int * q) // 使用指针 use pointers
{
        int temp;
        temp = *p; // 使用* p，* q表示变量值 use *p, *q for values of variables
        *p = *q;
        *q = temp;
}
void swapv (int a, int b) // 尝试使用值 try using values
{
        int temp;
        temp = a; // 使用a，b表示变量值 use a, b for values of variables
        a = b;
        b = temp;
}
