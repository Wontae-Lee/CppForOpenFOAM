#include <algorithm>
#include <vector>
#include <chrono>
#include <iostream>

bool cmp(float a, float b) { return a > b; }

class Cmp
{
public:
    bool operator()(float a, float b)
    {
        return a > b;
    }
};

int main(int argc, char **argv)
{
    int maxSize = 1000;
    if (argc > 1)
    {
        maxSize = std::stoi(argv[1]);
    }

    std::cout << "Size of data : " << maxSize << std::endl;
    std::vector<float> fptrData(maxSize);
    for (auto iter = fptrData.begin(); iter != fptrData.end(); ++iter)
    {
        *iter = rand() * maxSize;
    }

    // copy
    std::vector<float> functorData(fptrData);
    std::vector<float> lambdaData(fptrData);

    auto start = std::chrono::system_clock::now();
    std::sort(fptrData.begin(), fptrData.end(), cmp);
    auto end = std::chrono::system_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "elapsed time(ns): " << duration.count() << std::endl;

    start = std::chrono::system_clock::now();
    std::sort(
        lambdaData.begin(),
        lambdaData.end(),
        [](float a, float b)
        { return a > b; });
    end = std::chrono::system_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "elapsed time (ns): " << duration.count() << std::endl;
    return 0;
}
