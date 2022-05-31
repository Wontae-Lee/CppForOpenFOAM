#include <iostream>

class A;
class B
{
public:
    void printA(A &a);
};

class A
{
private:
    int var;

public:
    A() : var(2) {}
    friend void B::printA(A &a);
};

void B::printA(A &a)
{
    std::cout << a.var << std::endl;
}

int main(int argc, char **argv)
{
    A a;
    B b;
    b.printA(a);
    return 0;
}
