// temptempover.cpp -- template overloading
#include <iostream>
template <typename T> // 模板 A template A
void ShowArray (T arr[], int n);
template <typename T> // 模板 B template B
void ShowArray (T * arr[], int n);
struct debts
{
        char name[50];
        double amount;
};
int main(void)
{
        using namespace std;
        int things[6] = {13, 31, 103, 301, 310, 130};
        struct debts mr_E[3] = 
        {
                {"Ima Wolfe", 2400.0},
                {"Ura Foxe", 1300.0},
                {"Iby Stout", 1800.0}
        };
        double * pd[3];
        // 设置指向mr_E中结构成员amount的指针 set pointers to the amount members of the structures in mr_E
        for ( int i = 0; i < 3; i ++ )
        {
                pd[i] = &mr_E[i].amount;
        }
        cout << "Listing Mr.E's counts of things:\n";
        // things是一个int数组 things is an array of int
        ShowArray(things, 6); // 使用模板A uses template A
        cout << "Listing Mr.E's debts:\n";
        // pd是一个指向double的指针数组 pd is an array of pointers to double
        ShowArray(pd, 3); // 使用模板B(更具体) uses template B (more specialized)
        return 0;
}
template <typename T>
void ShowArray (T arr[], int n)
{
        using namespace std;
        cout << "template A\n";
        for ( int i = 0; i < n; i ++ )
        {
                cout << arr[i] << ' ';
        }
        cout << endl;
}
template <typename T>
void ShowArray (T * arr[], int n)
{
        using namespace std;
        cout << "template B\n";
        for ( int i = 0; i < n; i ++ )
        {
                cout << *arr[i] << ' ';
        }
        cout << endl;
}
