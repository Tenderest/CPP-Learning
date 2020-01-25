// protos.cpp -- using prototypes and function calls
#include <iostream>
void cheers (int ); // 原型:没有返回值 prototype: no return value
double cube (double x); // 原型:返回一个double prototype: return a double
int main(void)
{
        using namespace std;
        cheers(5); // 函数调用 function call
        cout << "Give me a number: ";
        double side;
        cin >> side;
        double volume = cube(side); // 函数调用 function call
        cout << "A " << side << "-foot cube has a volume of ";
        cout << volume << " cubic feet.\n";
        cheers(cube(2)); // 工作中的原型保护 prototype protection at work
        return 0;
}
void cheers (int n)
{
        using namespace std;
        for ( int i = 0; i < n; i ++ )
        {
                cout << "Cheers!";
        }
        cout << endl;
}
double cube (double x)
{
        return x * x * x;
}
