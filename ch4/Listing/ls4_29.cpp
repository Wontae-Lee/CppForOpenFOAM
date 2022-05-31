#include <iostream>

void func(const int &&a)
{
    std::cout << "rvalue argument" << std::endl;
}
