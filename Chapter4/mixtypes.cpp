// mixtypes.cpp -- some type combinations
#include <iostream>
#include <ostream>
struct antarctica_years_end
{
        int year;
        /* 一些非常有趣的数据，等等 some really interesting data, etc. */
};
int main(void)
{
        antarctica_years_end s01, s02, s03;
        s01.year = 1998;
        antarctica_years_end * pa = &s02;
        pa->year = 1999;
        antarctica_years_end trio[3]; // 3 个结构的数组 array of 3 structures
        trio[0].year = 2003;
        std::cout << trio->year << std::endl;
        const antarctica_years_end * arp[3] = {&s01, &s02, &s03};
        std::cout << arp[1]->year << std::endl;
        const antarctica_years_end ** ppa = arp;
        auto ppb = arp; // c++ 11自动类型推断 C++11 automatic type deduction
        // 或者使用const antarctica_years_end ** ppb = arp 
        std::cout << (*ppa)->year << std::endl;
        std::cout << (*(ppb + 1))->year << std::endl;
        return 0;
}
