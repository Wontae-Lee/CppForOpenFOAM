#include <iostream>
#include <fstream>
#include <cmath>

int main(int argc, char **argv)
{
    const double pi = std::atan2(1.0, 1.0) * 4;

    double x, delx;

    std::ofstream ofs("sine.csv");
    delx = pi / 10;

    ofs << "time, sine" << std::endl;
    for (int i = 0; i < 11; ++i)
    {
        x = delx * i;
        ofs << x << ", " << std::sin(x) << std::endl;
    }
    ofs.close();
    return 0;
}