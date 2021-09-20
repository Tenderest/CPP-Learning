// frnd2tmp.cpp -- template class with non-template fridends
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
        private:
                T item;
                static int ct;
        public:
                HasFriend (const T & i) : item(i) { ct ++; }
                ~HasFriend () { ct --; }
                friend void counts ();
                friend void reports (HasFriend<T> & ); // template parameter 模板参数
};

// each specialization has its own static data member
// 每个具体化都有自己的静态数据成员
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
// 所有HasFriend <T>类的非模板友元
void counts ()
{
        cout << "int count: " << HasFriend<int>::ct << "; ";
        cout << "double count: " << HasFriend<double>::ct << endl;
}

// non-template friend to the HasFriend<int> class
// HasFriend <int>类的非模板友元
void reports (HasFriend<int> & hf)
{
        cout << "HasFriend<int>: " << hf.item << endl;
}
//
// non-template friend to the HasFriend<double> class
// HasFriend <double>类的非模板友元
void reports (HasFriend<double> & hf)
{
        cout << "HasFriend<double>: " << hf.item << endl;
}

int main(void)
{
        cout << "No objects declared: ";
        counts();
        HasFriend<int> hfi1(10);
        cout << "After hfi1 declared: ";
        counts();
        HasFriend<int> hfi2(20);
        cout << "After hfi2 declared: ";
        counts();
        HasFriend<double> hfdb(10.5);
        cout << "After hfdb declared: ";
        counts();

        reports(hfi1);
        reports(hfi2);
        reports(hfdb);

        return 0;
}
