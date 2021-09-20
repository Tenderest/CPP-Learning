#include <iostream>
int main(void)
{
    // [...](...) mutable throwSpec -> retType {...}
    // mutable 可修改 throwSpec 抛出什么异常 retType 返回值类型
    // 出现一个必须要写小括号
    // 括号中写参数，调用的时候传递，函数内部的变量名会覆盖外部变量名
    int a = 10;
    std::cout << [=](int a) -> std::string {
        // std::cout << "hello lambda " << a << " " << b << std::endl;
        std::cout << "hello lambda " << a << std::endl;
        return "return value";
    }(11) << std::endl;
    return 0;
}
