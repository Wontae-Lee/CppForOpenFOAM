#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

// 처음 조건
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

// f(k) = omega^2 - g*k*tanh(k*h)
double f(double x)
{
    double k0(x);
    k0 = (omega * omega - gravity * k0 * std::tanh(k0 * h));
    return k0;
}

// f'(k) = -g*tahn(k*h) - g*k*h*(1 - tanh^2(k*h))
double fprime(double x)
{
    double k0(x);
    k0 = (-gravity * tanh(k0 * h) - gravity * k0 * h * (1 - std::tanh(k0 * h) * std::tanh(k0 * h)));
    return k0;
}

double find_root(std::vector<std::pair<double, double>> &pair_r, double x0, double (*f)(double x), double (*fprime)(double x))
{

    double k0(x0);

    std::cout << "wave number for deep water: " << k0 << std::endl;

    double k = k0;
    pair_r.push_back(std::make_pair(k, k - k0));

    for (int i = 0; i < 10; ++i)
    {

        std::cout << "iter : " << i << std::endl;
        k = k0 - f(k0) / fprime(k0);
        pair_r.push_back(std::make_pair(k, k - k0));

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
    std::vector<std::pair<double, double>> pair_r;
    std::cout << find_root(pair_r, k0, f, fprime) << std::endl;

    int index = 0;
    for (auto &n : pair_r)
    {
        std::cout << "현재 index: " << index << std::endl;
        std::cout << "first: " << n.first << std::endl;
        std::cout << "second: " << n.second << std::endl;
        index++;
    }

    return 0;
}