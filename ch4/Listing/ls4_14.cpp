#include <iostream>

class A
{
private:
    int var;

public:
    A() : var(2) {}

    /* void parameter list is not allowed
    friend void printA()
{
    std::cout << var<<std::endl;
}
*/
    friend void printA(A &a)
    {
        std::cout << a.var << std::endl;
    }
};

int main(int argc, char **argv)
{
    A a;
    // a.printA(); // this is not allowed
    // printA();
    printA(a);
    return 0;
}