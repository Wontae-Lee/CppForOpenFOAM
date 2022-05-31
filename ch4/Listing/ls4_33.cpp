#include <iostream>

class A
{
public:
    void func() & { std::cout << "lvalue argument" << std::endl; }
    void func() && { std::cout << "rvalue arguement" << std::endl; }
};

int main(int argc, char **argv)
{
    A obj;
    int a = 1;
    obj.func();
    A().func();
    return 0;
}