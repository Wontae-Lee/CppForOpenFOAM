#include <iostream>
#include <cmath>
#include <chrono>

const int nTableSize = 1000000;
float cosTable[nTableSize];
const float twoPi = 2 * M_PI;

int hashFunction(float x)
{
    return static_cast<int>(fmod(x / twoPi, 1.0) * nTableSize);
}

int main(int argc, char **argv)
{
    // initialize cosine table

    for (int i = 0; i < nTableSize; ++i)
    {
        cosTable[i] = cos(i * twoPi / nTableSize);
    }

    int nComponentWaves = 2000;
    float ntheta = twoPi / nComponentWaves;
    double radians[nComponentWaves];

    for (int i = 0; i < nComponentWaves; ++i)
    {
        radians[i] = ntheta * i;
    }

    double eta = 0;
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < nComponentWaves; ++i)
    {
        eta += cosTable[hashFunction(radians[i])];
    }
    auto end = std::chrono::system_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    std::cout << "elapsed time (ns): " << duration.count() << std::endl;

    start = std::chrono::system_clock::now();
    eta = 0;
    for (int i = 0; i < nComponentWaves; ++i)
    {
        eta += cosTable[hashFunction(radians[i])];
    }
    end = std::chrono::system_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "elapsed time(ns): " << duration.count() << std::endl;

    return 0;
}