#include <iostream>
int LongToMa (int );
int main(void)
{
        using namespace std;
        int longs;
        cout << "Enter how many longs: ";
        cin >> longs;
        cout << "Ma = " << LongToMa(longs) << endl;
        return 0;
}

int LongToMa (int ma)
{
        // 1 long = 220 码
        int Mas = ma * 220;
        return Mas;
}
