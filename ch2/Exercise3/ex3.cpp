#include <math.h>
#include <iostream>

double sqr(double x)
{
    return x * x;
}

double sqrt(double x)
{
    return std::pow(x, 0.5);
}

double cubic(double x)
{
    return x * x * x;
}

int main()
{

    double x = 3;
    std::cout << "x = " << x << std::endl;
    std::cout << "x 의 제곱 = " << sqr(x) << std::endl;
    std::cout << "x 의 제곱근 = " << sqrt(x) << std::endl;
    std::cout << "x 의 세제곱 = " << cubic(x) << std::endl;

    return 0;
}