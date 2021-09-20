// sumafile.cpp -- functions with an array argument
#include <iostream>
#include <fstream> // 文件I/O支持 file I/O support
#include <cstdlib> // 支持exit() support for exit()
const int SIZE = 60;
int main(void)
{
        using namespace std;
        char filename[SIZE];
        ifstream inFile; // 用于处理文件输入的对象 object for handling file input
        cout << "Enter name of data file: ";
        cin.getline(filename, SIZE);
        inFile.open(filename); // 将inFile与文件关联 associate inFile with a file
        if ( !inFile.is_open() ) // 打开文件失败 failed to open file
        {
                cout << "Could not open the file " << filename << endl;
                cout << "program terminating.\n";
                exit(EXIT_FAILURE);
        }
        double value;
        double sum = 0.0;
        int count = 0; // 读取的项目数 number of items read
        inFile >> value; // 获取第一个值 get first value
        while ( inFile.good() ) // 当输入良好而不是在EOF时 while input good and not at EOF
        {
                ++ count; // 读取一个项目 one more item read
                sum += value; // 计算运行总数 calculate running total
                inFile >> value; // 获取下一个值 get next value
        }
        if ( inFile.eof() )
        {
                cout << "End of file reached.\n";
        }
        else if ( inFile.fail() )
        {
                cout << "Input terminated by data mismatch.\n";
        }
        else
        {
                cout << "Input terminated for unknown reason.\n";
        }
        if ( count == 0 )
        {
                cout << "No data processed.\n";
        }
        else
        {
                cout << "Items read: " << count << endl;
                cout << "Sum: " << sum << endl;
                cout << "Aerage: " << sum / count << endl;
        }
        inFile.close(); // 完成文件 finished with the file
        return 0;
}
