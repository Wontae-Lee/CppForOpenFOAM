#include <iostream>
double sqr(const double &x) { return x * x; }
int main()
{
    double x = 1.4;
    std::cout << sqr(x) << std::endl;
    // std::cout << sqr(1.4) << std::endl; //error
    return 0;
}