#include <iostream>
#include <cmath>

class dispersionRelation
{
    const double pi_;
    const double grav_;
    double omega_;
    double h_;

public:
    dispersionRelation(double omega, double h)
        : pi_(M_PI),
          grav_(9.81),
          omega_(omega),
          h_(h)
    {
    }

    double operator()(double k);
    double derivative(double k);
};

double dispersionRelation::operator()(double k)
{
    k = (omega_ * omega_ - grav_ * k * std::tanh(k * h_));
    return k;
}
double dispersionRelation::derivative(double k)
{
    k = (-grav_ * tanh(k * h_) - grav_ * k * h_ * (1 - std::tanh(k * h_) * std::tanh(k * h_)));
    return k;
}

double find_root(double x0, dispersionRelation &f)
{
    double x;
    x = x0;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "iter: " << i << std::endl;
        x = x0 - f(x0) / f.derivative(x0);
        std::cout << "inter x: " << x << std::endl;
        if (std::fabs(x - x0) < 1e-4)
            break;
    }

    return x;
}

int main(int argc, char **argv)
{
    const double h = 10;
    const double pi = M_PI;
    const double gravity = 9.81;
    const double omega = pi / 2;

    // inital value is set to the solution for deep water, k = omega^2/g
    double k0 = omega * omega / gravity;
    dispersionRelation wave_k(omega, h);

    std::cout << find_root(k0, wave_k) << std::endl;

    return 0;
}