#include <iostream>

using namespace std;

class A
{
public:
    virtual void func(int a = 0)
    {
        cout << "________" << endl;
        cout << "A" << endl;
        cout << "a: " << a << endl;
    }
};

class B : public A
{
public:
    virtual void func(int a = 1)
    {
        cout << "________" << endl;
        cout << "B" << endl;
        cout << "a: " << a << endl;
    }
};

int main()
{
    A *a = new B();
    B *b = new B();
    B bb;
    a->func();
    b->func();
    bb.func();

    delete a;
    delete b;

    return 0;
}