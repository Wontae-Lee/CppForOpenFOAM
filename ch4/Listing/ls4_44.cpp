#include <iostream>

class A
{
public:
    virtual void f(int x) const { std::cout << "A::f" << std::endl; }
};
class B : public A
{
public:
    void f(float x) const { std::cout << "B::f" << std::endl; }
    void f(int x) const { std::cout << "B::f" << std::endl; }
};

int main()
{
    B b;
    b.f(123);
    return 0;
}
