#include <iostream>

double An(unsigned long n, double step, double init)
{
    // return n>0? An(n-1, step, init) +step : init;

    if (n == 0)
    {
        return init;
    }
    else
    {
        An(n - 1, step, init) + step;
    }
}

int main(int argc, char **argv)
{
    double init = 1;
    double step = 2;
    double result = An(10, step, init);
    std::cout << "result: " << result << std::endl;

    return 0;
}