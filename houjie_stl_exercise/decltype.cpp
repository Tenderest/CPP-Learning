#include <iostream>
#include <vector>
int main(void)
{
    std::vector<int> v;
    decltype(v)::value_type a;
    std::cout << a << std::endl;

    std::vector<int>::iterator vIter = v.begin();

    std::iterator_traits<decltype(v)::iterator>::iterator_category ic; // std::random_access_iterator_tag
    std::iterator_traits<decltype(vIter)>::pointer ip; // int*
    std::iterator_traits<std::vector<int>::iterator>::value_type b = 2; // int
    // std::cout << ic << std::endl;
    std::cout << (typeid(ic) == typeid(std::random_access_iterator_tag)) << std::endl; // true
    
    std::cout << b << std::endl;
    // std::cout << std::iterator_traits<vIter> << std::endl;
    return 0;
}
