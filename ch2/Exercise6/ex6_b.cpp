#include <iostream>
#include <cmath>

namespace ex6
{
    const double h = 10;
    const double pi = M_PI;
    const double gravity = 9.81;
    const double omega = pi / 2;
}

using ex6::gravity;
using ex6::h;
using ex6::omega;
using ex6::pi;

double find_root(double x0)
{

    double k0(x0);

    // f(k) = omega^2 - g*k*tanh(k*h)
    // f'(k) = -g*tahn(k*h) - g*k*h*(1 - tanh^2(k*h))

    std::cout << "wave number for deep water: " << k0 << std::endl;

    double k = k0;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "iter : " << i << std::endl;
        k = k0 - (omega * omega - gravity * k0 * std::tanh(k0 * h)) /
                     (-gravity * tanh(k0 * h) - gravity * k0 * h * (1 - std::tanh(k0 * h) * std::tanh(k0 * h)));

        std::cout << "inter k: " << k << std::endl;
        if (std::fabs(k - k0) < 1e-4)
            break;
        k0 = k;
    }
    std::cout << "wave number: ";
    return k;
}

int main(int argc, char **argv)
{

    // inital value is set to the solution for deep water, k = omega^2/g
    double k0 = omega * omega / gravity;
    std::cout << find_root(k0) << std::endl;

    return 0;
}