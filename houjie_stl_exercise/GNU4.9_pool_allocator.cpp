#include <iostream>
#include <ext/hash_map>
#include <memory>
int main(void)
{
    // __gnu_cxx::__pool_alloc
    __gnu_cxx::hash_map<int, int>;
    __gnu_cxx::allocator<int>;
    return 0;
}
