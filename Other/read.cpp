#include <fstream>
#include <iostream>
#include <cstdlib>

void writeFile()
{
	std::fstream outfile;
	outfile.open("my.txt", std::ios_base::out);
	if (outfile.is_open())
	{
		std::cout << "file is open, wait to write some text" << std::endl;
	}
	else {
		std::cout << "file is not open!!!" << std::endl;
		std::exit(1);
	}
	
	outfile << "*****" << std::endl;
	outfile << "* 我 *" << std::endl;
	outfile.close();
}

void readFile()
{
	std::ifstream infile;
	infile.open("test.txt", std::ios_base::in);
	if (infile.is_open())
	{
		std::cout << "file is open" << std::endl;
	}
	char ch;
	while (!infile.eof()){
		infile.get(ch);
		std::cout << ch;
	}

	// char ch;
	// os.seekp(0);
	// while (!os.eof())
	// {
	// 	os.get(ch);
	// 	std::cout << ch;
	// }
	infile.close();
}

int main(void)
{
	writeFile();
	readFile();
	return 0;
}