#include <iostream>
int main(void)
{
        // 1 foot = 12 inch = 30.48 cm
        // 1 inch = 2.54 cm
        using namespace std;
        const unsigned int foot_convert_inch = 12;
        unsigned int man_hight_inch;
        unsigned int man_hight_foot;
        cout << "Enter your hight(inch):__\b\b"; // 输入您的高(英寸):
        cin >> man_hight_inch;
        cout << "Show your hight in feets: " << man_hight_inch / foot_convert_inch << " feets "
             << man_hight_inch % foot_convert_inch << " inchs.\n"; // 以英尺为单位显示您的身高:
        return 0;
}
// foot = inch / foot_convert_inch;
// inch = inch % foot_convert_inch;
