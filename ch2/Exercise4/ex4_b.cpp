
#include <iostream>

double an(double a0, int i, double d)
{
    double ai = 0.0;
    i -= 1;

    if (i == 0)
    {

        return a0;
    }
    else
    {

        return ai = ai + d + an(a0, i, d);
    }
}

int main()
{
    double a0 = 10.5;
    double a;
    double d = 5;
    int n = 10;

    double result = an(a0, n, d);
    std::cout << result << std::endl;

    return 0;
}