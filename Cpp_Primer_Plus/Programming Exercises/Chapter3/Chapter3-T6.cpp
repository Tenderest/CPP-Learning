#include <iostream>
int main(void)
{
        using namespace std;
        float mileage;
        float gasoline;

        cout << "Enter number of Mileage and Gasoline:\n";
        cout << "Mileage: ";
        cin >> mileage;
        cout << "Gasoline: ";
        cin >> gasoline;
        cout << mileage/gasoline << " M/G" << endl;
        return 0;
}
// 3 mileage 2 gasoline
// 1 gasoline 3/2 mileage
