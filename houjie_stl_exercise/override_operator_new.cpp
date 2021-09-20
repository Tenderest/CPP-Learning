#include <iostream>

class Foo {
private:
    int a;
public:
    void* operator new(size_t size);
    void setMember(int a) {this->a = a;}
    int getMember() {return this->a;}
    ~Foo() {std::cout << "destructor..." << std::endl;}
};

void* Foo::operator new(size_t size)
{
    std::cout << "override operator new myself" << std::endl;
    std::cout << "argument size: " << size << std::endl;
    Foo* p = (Foo*)malloc(size);
    return p;
}

int main(void)
{
    std::cout << "sizeof(Foo) is: " << sizeof(Foo) << std::endl;
    Foo* pf = new Foo;
    pf->setMember(3);
    std::cout << "the pointer point object member is: " << pf->getMember() << std::endl;
    delete pf;
    return 0;
}
