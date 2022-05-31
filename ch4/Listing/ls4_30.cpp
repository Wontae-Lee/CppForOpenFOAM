#include <iostream>

class A
{
public:
    void func(const int &a) { std::cout << "lvalue argument" << std::endl; }
    void func(const int &&a) { std::cout << "rvalue arguement" << std::endl; }
};

int main(int argc, char **argv)
{
    A obj;
    int a = 1;
    obj.func(a);
    obj.func(1);
    return 0;
}