#include <iostream>
double F_C (double );
int main(void)
{
        // 华氏温度 = 1.8 * 摄氏温度 + 32.0
        using namespace std;
        double Celsius, Fahrenheit;
        cout << "Enter a Celsius value: ";
        cin >> Celsius;
        cout << Celsius << " degrees Celsius is " << F_C(Celsius) << " degrees Fahrenheit" << endl;
        return 0;
}

double F_C (double temp)
{
        double Fahrenheit;
        Fahrenheit = temp * 1.8 + 32.0;
        return Fahrenheit;
}
