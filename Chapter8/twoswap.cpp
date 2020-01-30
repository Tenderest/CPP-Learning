// twoswap.cpp -- specialization overrides a template
#include <iostream>
template <typename T>
void Swap (T & a, T & b);
struct job
{
        char name[40];
        double salary;
        int floor;
};
// 显式具体化 explicit specialization
template <> void Swap<job> (job & j1, job & j2);
void Show (job & j);
int main(void)
{
        using namespace std;
        cout.precision(2);
        cout.setf(ios::fixed, ios::floatfield);
        int i = 10, j = 20;
        cout << "i, j = " << i << ", " << j << ".\n";
        cout << "Using compiler-generated int swapper:\n";
        Swap(i, j); // 生成void Swap (int &， int &)
        cout << "Now i, j = " << i << ", " << j << ".\n";

        job sue = {
                "Susan Yaffee",
                73000.60,
                7
        };
        job sidney = {
                "Sideny Taffee",
                78060.72,
                9
        };
        cout << "Before job swapping:\n";
        Show(sue);
        Show(sidney);
        Swap(sue, sidney); // 使用void Swap(job &， job &) uses void Swap(job &, job &)
        cout << "Afetr job swapping:\n";
        Show(sue);
        Show(sidney);
        // cin.get();
        return 0;
}
template <typename T>
void Swap (T & a, T & b) // 普通版 general version
{
        T temp;
        temp = a;
        a = b;
        b = temp;
}
// 只交换一个工作结构的工资和底薪字段
// swaps just the salary and floor fields of a job structure
template <> void Swap<job> (job & j1, job & j2) // 具体化 specialization
{
        double t1;
        int t2;
        t1 = j1.salary;
        j1.salary = j2.salary;
        j2.salary = t1;
        t2 = j1.floor;
        j1.floor = j2.floor;
        j2.floor = t2;
}
void Show (job & j)
{
        using namespace std;
        cout << j.name << ": $" << j.salary
             << " on floor " << j.floor << endl;
}
