// outfile.cpp -- writing to a file
#include <iostream>
#include <fstream> // 用于文件I/O for file I/O
int main(void)
{
        using namespace std;
        char automobile[50];
        int year;
        double a_price;
        double d_price;
        ofstream outFile; // 创建输出对象 create object for output
        outFile.open("carinfo.txt"); // 与文件关联 associate with a file
        cout << "Enter the make and model of automobile: ";
        cin.getline(automobile, 50);
        cout << "Enter the model year: ";
        cin >> year;
        cout << "Enter the original asking price: ";
        cin >> a_price;
        d_price = 0.913 * a_price;
        // 使用cout在屏幕上显示信息 display information on screen with cout
        cout << fixed;
        cout.precision(2);
        cout.setf(ios_base::showpoint);
        cout << "Make and model: " << automobile << endl;
        cout << "Year: " << year << endl;
        cout << "Was asking $" << a_price << endl;
        cout << "Now asking $" << d_price << endl;
        // 现在使用outFile而不是cout做完全相同的事情 now da exact same things using outFile instead of cout
        outFile << fixed;
        outFile.precision(2);
        outFile.setf(ios_base::showpoint);
        outFile << "Make and model: " << automobile << endl;
        outFile << "Year: " << year << endl;
        outFile << "Was asking $" << a_price << endl;
        outFile << "Now asking $" << d_price << endl;
        outFile.close(); // 用文件完成 done with file
        return 0;
}
