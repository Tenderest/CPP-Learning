// arith.cpp -- some C++ arithmethic
#include <iostream>
int main(void)
{
        using namespace std;
        float hats, heads;
        cout.setf(ios_base::fixed, ios_base::floatfield); // 固定点（小数点）
        cout << "Enter a number: ";
        cin >> hats;
        cout << "Enter another number: ";
        cin >> heads;
        cout << "hats = " << hats << "; heads = " << heads << endl;
        cout << "hats + heads = " << hats + heads << endl;
        cout << "hats - heads = " << hats - heads << endl;
        cout << "hats * heads = " << hats * heads << endl;
        cout << "hats / heads = " << hats / heads << endl;
        return 0;
}
