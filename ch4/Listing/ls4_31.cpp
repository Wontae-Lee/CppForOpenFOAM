#include <iostream>

class A
{
    void func() &
    {
        std::cout << "object is lvalue" << std::endl;
    }
};