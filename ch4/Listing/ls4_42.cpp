#include <iostream>

class A
{
public:
    virtual void f(int x) { std::cout << "A::f" << std::endl; }
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
