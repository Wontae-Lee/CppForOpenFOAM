#include <iostream>

class A
{

public:
    void func() { std::cout << " non-const object" << std::endl; }
    void func() const { std::cout << "object is const" << std::endl; }
};

int main(int argc, char **argv)
{
    A non_const_obj;
    const A const_obj;

    non_const_obj.func();
    const_obj.func();
    return 0;
}