#include <iostream>
int main(void)
{
        using namespace std;
        long long int world_people;
        long long int us_people;

        cout << "Enter the world's population: ";
        cin >> world_people;
        cout << "Enter the population of the US: ";
        cin >> us_people;
        float percent = (float) us_people / world_people;

        /* cout << fixed; */
        /* cout.precision(5); */
        /* cout.setf(ios_base::showpoint); */
        /* 定点表示小数点没有完成 */
        cout << "The population of the US is " << percent << "% of the world population.\n";
        return 0;
}
