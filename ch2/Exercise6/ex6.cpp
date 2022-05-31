#include <iostream>
#include <cmath>

int main(int argc, char **argv)
{
    const double h = 10;
    const double pi = M_PI;
    const double grav = 9.81;
    const double omega = pi / 2;

    // initial value is set to the solution for deep water, k = omega^2/g
    double k0 = omega * omega / grav;
    double k;

    // f(k) = omega^2 - g*k*tanh(k*h)
    // f'(k) = -g*tanh(k*h) - g*k*h*(1 - tanh^2(k*h))

    std::cout << "wave number for deep water: " << k0 << std::endl;

    // Newton-Raphson start
    k = k0;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "iter : " << i << std::endl;
        // k = k0 - f(k0)/fprime(k0);
        k = k0 -
            (omega * omega - grav * k0 * std::tanh(k0 * h)) /
                (-grav * tanh(k0 * h) - grav * k0 * h * (1 - std::tanh(k0 * h) * std::tanh(k0 * h)));

        std::cout << "inter k : " << k << std::endl;
        if (std::fabs(k - k0) < 1e-4)
            break;
        k0 = k;
    }

    std::cout << "wave number : " << k << std::endl;

    return 0;
}
