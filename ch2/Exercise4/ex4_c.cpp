
#include <iostream>

double an(double a0, int i, double r)
{
    double ai = 1.0;
    i -= 1;

    if (i == 0)
    {

        return a0;
    }
    else
    {

        return ai = ai * r * an(a0, i, r);
    }
}

int main()
{
    double a0 = 10.5;
    double a;
    double r = 5;
    int n = 10;

    double result = an(a0, n, r);
    std::cout << result << std::endl;

    return 0;
}