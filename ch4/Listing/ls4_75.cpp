#include <iostream>

template <unsigned int n>
class factorial
{
public:
    static const unsigned int value = n * factorial<n - 1>::value;
};

template <>
class factorial<0>
{
public:
    static const unsigned int value = 1;
};

int main(int argc, char **argv)
{
    std::cout << factorial<4>::value << std::endl;
    return 0;
}