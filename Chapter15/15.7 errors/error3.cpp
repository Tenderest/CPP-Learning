// error3.cpp -- using an exception
#include <iostream>

double hmean (double a, double b);

int main(void)
{
	double x, y, z;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try {                    // start of try block try块的开始
			z = hmean(x, y);
		}                        // end of try block try块的结尾
		catch (const char * s) { // start of exception handler 异常处理程序的开始
			std::cout << s << std::endl;
			std::cout << "Enter a new pair of number: ";
			continue;
		}                        // end of handler 处理程序的结尾
		std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << std::endl;
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

double hmean (double a, double b)
{
	if (a == -b)
	{
		throw "bad hmean() arguments: a = -b not allowed";
	}
	return 2.0 * a * b / (a + b);
}
