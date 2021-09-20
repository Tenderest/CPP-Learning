#include <iostream>
#include <string>
#include <bitset> // line 58

// 利用可变参数类模板，递归继承
// recursive inheritance
namespace ff {
    template<typename... Values> class ff_tuple;
    template<> class ff_tuple<> {};

    template<typename Head, typename... Tail>
    class ff_tuple<Head, Tail...> : private ff_tuple<Tail...>
    {
        typedef ff_tuple<Tail...> inherited;
        protected:
            Head m_head;
        public:
            ff_tuple() {}
            ff_tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}
            auto head() -> decltype(m_head) {return m_head;}
            // Head head() {return m_head;}
            inherited& tail() {return *this;}
    };


    template<typename... Values> class f_tuple;
    template<> class f_tuple<> {};

    template<typename Head, typename... Tail>
    class f_tuple<Head, Tail...> : private f_tuple<Tail...>
    {
        typedef f_tuple<Tail...> composition;
        protected:
            Head m_head;
            composition m_tail;
        public:
            f_tuple() {}
            f_tuple(Head v, Tail... vtail) : m_head(v), m_tail(vtail...) {}
            // auto head() -> decltype(m_head) {return m_head;}
            Head head() {return m_head;}
            composition& tail() {return m_tail;}
    };
}

// 利用可变参数模板，递归复合，其中内含一个对象
// recursive composition

int main(void)
{
    std::cout << "使用递归继承" << std::endl;
    ff::ff_tuple<int, float, std::string> t(20, 1.2, "ffmm");
    std::cout << "使用递归继承 size: " << sizeof(t) << std::endl;
    std::cout << t.head() << std::endl;
    std::cout << t.tail().head() << std::endl;
    std::cout << t.tail().tail().head() << std::endl;

    std::cout << "使用递归复合" << std::endl;
    ff::f_tuple<int, float, std::string, std::bitset<16>>
    tt(04, 1.2, "ffmm", std::bitset<16>(18));
    std::cout << "使用递归复合 size: " << sizeof(tt) << std::endl;
    std::cout << tt.head() << std::endl;
    std::cout << tt.tail().head() << std::endl;
    std::cout << tt.tail().tail().head() << std::endl;
    std::cout << tt.tail().tail().tail().head() << std::endl;
    // std::cout << tt.tail().tail().tail().tail().head() << std::endl;
    return 0;
}
