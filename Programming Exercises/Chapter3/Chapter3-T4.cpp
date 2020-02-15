#include <iostream>
int main(void)
{
        // 1 day = 24 hours
        // 1 hour = 60 minutes
        // 1 mintue = 60 seconds
        using namespace std;
        const int day_convert_hour = 24;
        const int day_convert_minute = 60 * 24;
        const int day_convert_seconds = 24 * 60 * 60;
        long int total_seconds;

        cout << "Enter the number of seconds: ";
        cin >> total_seconds;

        unsigned int days = total_seconds / day_convert_seconds;
        unsigned int hours = (total_seconds - (days * day_convert_seconds) ) / (60 * 60);
        unsigned int minutes = (total_seconds - (days * day_convert_seconds) - (hours * 60 * 60) ) / 60;
        unsigned int seconds = total_seconds - (days * day_convert_seconds) - (hours * 60 * 60) - (minutes * 60);

        cout << total_seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds.\n";
        return 0;
}
// unsigned int days = total_seconds / day_convert_seconds;
// unsigned int hours = (total_seconds - (days * day_convert_seconds) ) / (60 * 60);
// unsigned int minutes = (total_seconds - (days * day_convert_seconds) - (hours * 60 * 60) ) / 60;
// unsigned int seconds = total_seconds - (days * day_convert_seconds) - (hours * 60 * 60) - (minutes * 60);
