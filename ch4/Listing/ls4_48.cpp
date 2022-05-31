#include <iostream>

using namespace std;

class A
{
public:
    virtual void func() { cout << "A" << endl; }
};

class B : public A
{
public:
    virtual void func() { cout << "B" << endl; }
};

int main()
{
    B *b = new B;
    b->func();
    A *a = b;
    a->func();

    delete b;

    return 0;
}