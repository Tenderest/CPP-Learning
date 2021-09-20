// address.cpp -- using the & operator to find addresses
#include <iostream>
int main(void)
{
        using namespace std;
        int donuts = 6;
        double cups = 4.5;
        cout << "donuts value = " << donuts;
        cout << " and donuts address = " << &donuts << endl;
        // 注意:你可能需要使用unsigned (&donuts) NOTE: you may need to use unsigned (&donuts)
        // 和unsigned (&cups) and unsigned (&cups)
        cout << "cups value = " << cups;
        cout << " and cups address = " << &cups << endl;
        return 0;
}
