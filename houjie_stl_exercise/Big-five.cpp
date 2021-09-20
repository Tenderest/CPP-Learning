// 5 种构造函数的使用
#include <iostream>
using std::cout;
using std::endl;


class Foo {
    public:
        int _c;
    public:
        Foo() {
            _c = 10;
            cout << "non-argument construct " << _c << endl;
        }

        Foo(int _i) {
            _c = _i;
            cout << "int argument construct " << _c << endl;
        }

        Foo(const Foo& copy_foo) {
            _c = copy_foo._c + std::rand();
            cout << "copy construct " << _c <<  endl;
        }

        ~Foo() {
            cout << "deconstruct " << _c << endl;
        }

        Foo& operator= (const Foo& asign_foo) {
            _c = asign_foo._c + std::rand();
            cout << "asignment construct " << _c << endl;
            return *this;
        }
};


int main(void)
{
    Foo f1;
    Foo f2(1);
    Foo* f3 = new Foo(2);
    Foo* f4 = new Foo(3);
    Foo f5(f2);
    f5 = f2;

    delete f3;
    delete f4;

    return 0;
}
