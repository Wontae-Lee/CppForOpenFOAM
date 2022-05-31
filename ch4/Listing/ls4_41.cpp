#include <iostream>

class A
{
};
class B : public A
{
public:
    void f(float x) { std::cout << "B::f" << std::endl; }
};

int main()
{
    B b;
    b.f(5);
    return 0;
}