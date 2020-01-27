// arfupt.cpp -- an array of function pointers
#include <iostream>
// 各种符号，相同的签名 various natations, same signatures
const double * f1 (const double ar[], int n);
const double * f2 (const double [], int );
const double * f3 (const double *, int );
int main(void)
{
        using namespace std;
        double av[3] = {1112.3, 1542.6, 2227.9};
        // 指向函数的指针 pointer to a function
        const double * (* p1) (const double *, int ) = f1;
        auto p2 = f2;
        // C++ 11之前的版本可以使用以下代码代替 pre-C++11 use the following code instead
        // const double * (* p2) (const double *, int ) = f2;
        cout << "Using pointers to functions:\n";
        cout << " Address Value\n";
        cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
        cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
        // pa一个指针数组 pa an array of pointers
        // auto不支持列表初始化 auto doesn't work with list initialization
        const double * (* pa[3]) (const double *, int ) = {f1, f2, f3};
        // 但是它确实可以初始化为单个值 but it does work for initializing to a single value
        // pb指向pa的第一个元素的指针 pb a pointer to first element of pa
        auto pb = pa;
        // C++ 11之前的版本可以使用以下代码代替 pre-C++11 use the following code instead
        // const double * (** pb) (const double *, int ) = pa;
        cout << "\nUsing an -array* of pointers to functions:\n";
        cout << " Address Value\n";
        for ( int i = 0; i < 3; i ++ )
        {
                cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
        }
        cout << "\nUsing an -pointer* to a pointers to functions:\n";
        cout << " Address Value\n";
        for ( int i = 0; i < 3; i ++ )
        {
                cout << pb[i](av, 3) << ": " << *pa[i](av, 3) << endl;
        }
        // 那么一个指向函数指针数组的指针呢
        // what about a pointer to an array of function pointers
        cout << "\nUsing pointers to an array of pointers:\n";
        cout << " Address Value\n";
        // 声明pc的简单方法 easy way to declare pc
        auto pc = &pa;
        // C++ 11之前的版本可以使用以下代码代替 pre-C++11 use the following code instead
        // const double * (* (* pc)[3] ) (const double *, int ) = &pa;
        cout << (*pc)[0](av, 3) << ": " << * (*pc)[0](av, 3) << endl;
        // 声明pd的困难方法 hard way to declare pd
        const double * (* (* pd)[3] ) (const double *, int ) = &pa;
        // 将返回值存储在pdb中 store return value in pdb
        const double * pdb = (*pd)[1](av, 3);
        cout << pdb << ": " << *pdb << endl;
        // 替代说明 alternative notation
        cout << (* (*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
        // cin.get();
        return 0;
}
// 一些相当沉闷的功能 some rather dull functions
const double * f1 (const double ar[], int n)
{
        return ar;
}
const double * f2 (const double ar[], int n)
{
        return ar + 1;
}
const double * f3 (const double * ar, int n)
{
        return ar + 2;
}
