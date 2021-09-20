// newplace.cpp -- using placment new
#include <iostream>
#include <new> // 用于新new for placement new
const int BUF = 512;
const int N = 5;
char buffer[BUF]; // 内存块 chunk of memory
int main(void)
{
        using namespace std;
        double * pd1, * pd2;
        int i;
        cout << "Calling new and placement new:\n";
        pd1 = new double[N]; // 使用堆 use heap
        pd2 = new (buffer) double[N]; // 使用缓冲区数组 use buffer array
        for ( i = 0; i < N; i ++ )
        {
                pd2[i] = pd1[i] = 1000 + 20.0 * i;
        }
        cout << "Memory addresses:\n" << "  heap: " << pd1
             << "  static: " << (void *) buffer << endl;
        cout << "Memory contents:\n";
        for ( i = 0; i < N; i ++ )
        {
                cout << pd1[i] << " at " << &pd1[i] << "; ";
                cout << pd2[i] << " at " << &pd2[i] << endl;
        }
        cout << "\nCalling new and placement new a second time:\n";
        double * pd3, * pd4;
        pd3 = new double[N]; // 查找新地址 find new address
        pd4 = new (buffer) double[N]; // 覆盖旧数据 overwrite old data
        for ( i = 0; i < N; i ++ )
        {
                pd4[i] = pd3[i] = 1000 + 40.0 * i;
        }
        cout << "Memory contents:\n";
        for ( i = 0; i < N; i ++ )
        {
                cout << pd3[i] << " at " << &pd3[i] << "; ";
                cout << pd4[i] << " at " << &pd4[i] << endl;
        }
        cout << "\nCalling new and placement new a third time:\n";
        delete [] pd1;
        pd1 = new double[N];
        pd2 = new (buffer + N * sizeof(double)) double[N];
        for ( i = 0; i < N; i ++ )
        {
                pd2[i] = pd1[i] = 1000 + 60.0 * i;
        }
        cout << "Memory contents:\n";
        for ( i = 0; i < N; i ++ )
        {
                cout << pd1[i] << " at " << &pd1[i] << "; ";
                cout << pd2[i] << " at " << &pd2[i] << endl;
        }
        delete [] pd1;
        delete [] pd3;
        return 0;
}
