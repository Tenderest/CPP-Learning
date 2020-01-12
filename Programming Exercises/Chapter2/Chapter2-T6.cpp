#include <iostream>
double LightYears_Units (double );
int main(void)
{
        // 1 光年 = 63240 天文单位
        using namespace std;
        double LightYears, Units;
        cout << "Enter the number of light years: ";
        cin >> LightYears;
        cout << LightYears << " light years = " << LightYears_Units(LightYears) << " astronomical units." << endl;
        return 0;
}

double LightYears_Units (double temp)
{
        double Units;
        Units = temp * 63240;
        return Units;
}
