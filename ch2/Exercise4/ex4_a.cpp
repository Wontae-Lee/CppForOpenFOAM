#include <math.h>

int main()
{
    double a0 = 0.l;
    double a;
    double d = 5;
    int n = 10;

    for (int i = 1; i <= n; ++i)
    {
        a = a0 * std::pow(d, i);
    }

    return 0;
}