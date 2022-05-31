#include <iostream>

double sqr(const double &x)
{
    std::cout << "lvalue argument" << std::endl;

    return x * x;
}

double sqr(const double &&x)
{
    std::cout << "rvalue argument" << std::endl;
    return x * x;
}

int main(int argc, char **argv)
{
    double x = 1.4;
    std::cout << sqr(x) << std::endl;
    std::cout << sqr(1.4) << std::endl;

    return 0;
}
