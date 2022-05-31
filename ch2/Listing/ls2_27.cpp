#include <iostream>
#include <cmath>

double sqr(double x)
{
    std::cout << "sqr" << std::endl;
    return x * x;
}

double sqrt(double x)
{
    std::cout << "sqrt" << std::endl;
    return pow(x, 0.5);
}

double cubic(double x)
{
    std::cout << "cubic" << std::endl;
    return x * x * x;
}

int main(int argc, char **argv)
{
    const char *choice = "sqr";
    double x = 3;
    double result;

    if (choice == "sqr")
    {
        result = sqr(x);
    }
    else if (choice == "cubic")
    {
        result = sqrt(x);
    }

    else if (choice == "cubic")
    {
        result = cubic(x);
    }

    std::cout << "result: " << result << std::endl;
    return 0;
}