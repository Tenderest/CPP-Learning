#include <iostream>
int main(void)
{
        // 1 degrees = 60 minutes
        // 1 minutes = 60 seconds
        using namespace std;
        const int minutes_convert_degrees = 60;
        const int seconds_convert_degrees = 60 * 60;
        float f_degrees;
        float f_minutes;
        float f_seconds;

        cout << "Enter a latitude in degrees, minutes, and seconds:\n"; // 输入纬度(以度、分、秒为单位):
        cout << "First, enter the degrees: "; // 首先，输入度数
        cin >> f_degrees;
        cout << "Next, enter the minutes of arc: "; // 接下来，输入弧度的分钟数
        cin >> f_minutes;
        cout << "Finally, enter the seconds of arc: "; // 最后，输入弧度的秒数
        cin >> f_seconds;

        float total_degrees = f_degrees + (f_minutes / minutes_convert_degrees) + (f_seconds / seconds_convert_degrees);
        cout << f_degrees << " degrees, " << f_minutes << " minutes, " << f_seconds << " seconds = " << total_degrees << " degrees\n";
        return 0;
}
