#include <iostream>
#include <cmath>
int main(void)
{
        // 1 foot = 12 inch = 30.48 cm
        // 1 inch = 0.0254 m
        // 1 inch = 2.54 cm
        // 1 kg = 2.2 pound
        using namespace std;
        const int inch_convert_feet = 12;
        const float inch_convert_m = 0.0254;
        const float pound_convert_kg = 2.2;
        float man_hight_feets;
        float man_hight_inchs;
        float man_weight_pound;

        cout << "Enter your hight with how many feets and inchs:\n"; // 用英尺，英寸和磅输入身高和体重
        cout << "Feets:_\b";
        cin >> man_hight_feets;
        cout << "Inchs:_\b";
        cin >> man_hight_inchs;
        cout << "Weight:_\b";
        cin >> man_weight_pound;

        float total_inchs = (man_hight_feets * inch_convert_feet) + man_hight_inchs;
        float total_m = total_inchs * inch_convert_m;
        float total_kg = man_weight_pound / pound_convert_kg;
        float BMI = total_kg / total_m;

        cout << total_m << " m " << total_kg << " kg.\n";
        cout << "BMI = " << pow(BMI, 2) << endl;
        return 0;
}
// BMI = (weight / hight)^2
//          kg       m
// m = total_inchs * 0.0254
// kg = pound / 2.2
// inch = feet * inch_convert_feet
