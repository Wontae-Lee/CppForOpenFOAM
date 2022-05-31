#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "class A initializer invoked." << std::endl;
    }
};

int main()
{
    A a();
    std::cout << "------------" << std::endl;
    A b;

    return 0;
}