#include <iostream>

using namespace std;

class A
{
public:
    void func() { cout << "A" << endl; }
};

class B : public A
{
public:
    void func() { cout << "B" << endl; }
};

int main()
{
    B b;
    b.func();
    return 0;
}