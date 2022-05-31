#include <iostream>

class B;
class A
{
private:
    int var;

public:
    A() : var(2) {}
    friend B;
};

class B
{
public:
    void PrintA()
    {
        A a;
        std::cout << a.var << std::endl;
    }
};