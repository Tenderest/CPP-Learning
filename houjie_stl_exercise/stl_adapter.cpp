#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    using namespace std;
    std::vector<int> v;
    // std::cout <<
    // std::count_if(v.begin(), v.end(),
    //                 std::not1(std::bind2nd(std::less<int>(), 40))
    //              )
    // << std::endl;
    cout << count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 40)) );

    // typedef typename Operation::second_argument_type arg2_type;
    // typename Operation::result_type operator() (const typename Operation::first_argument_type& x)
    // binder2nd(const Operation& x, const typename Operotion::sceond_argument_type y) : op(x), value(y) {}
    return 0;
}
