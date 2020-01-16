// floatnum.cpp -- floating-point types
#include <iostream>
int main(void)
{
        using namespace std;
        cout.setf(ios_base::fixed, ios_base::floatfield); // 定点的；不动点的
        float tub = 10.0 / 3.0; // 好到大约6个地方 good to about 6 places
        double mint = 10.0 / 3.0; // 好到大约15个地方 good to about 15 places
        const float million = 1.0e6;
        cout << "tub = " << tub;
        cout << ", a million tubs = " << million * tub;
        cout << ",\nand ten million tubs = ";
        cout << 10 * million * tub << endl;
        cout << "mint = " << mint << " and a million mints = ";
        cout << million * mint << endl;
        return 0;
}
