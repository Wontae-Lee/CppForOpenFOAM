#include <cmath>
#include <iostream>
#include <map>
#include <string>

float Sqr(float x)
{
    std::cout << "Sqr function called" << std::endl;
    return x * x;
}

float Sqrt(float x)
{
    std::cout << "Sqrt function called" << std::endl;
    return pow(x, 0.5);
}

float Cubic(float x)
{
    std::cout << "Cubic function called" << std::endl;
    return x * x * x;
}

typedef float (*function1Ptr)(float);
std::map<std::string, function1Ptr> RTStable;

class SqrAddToTable
{
public:
    SqrAddToTable(const std::string &name)
    {
        RTStable.insert(std::pair<std::string, function1Ptr>(name, Sqr));
    }
};

class SqrtAddToTable
{
public:
    SqrtAddToTable(const std::string &name)
    {
        RTStable.insert(std::pair<std::string, function1Ptr>(name, Sqrt));
    }
};

class CubicAddToTable
{
public:
    CubicAddToTable(const std::string &name)
    {
        RTStable.insert(std::pair<std::string, function1Ptr>(name, Cubic));
    }
};

SqrAddToTable SqrDelegator("Sqr");
SqrtAddToTable SqrtDelegator("Sqrt");
CubicAddToTable CubicDelegator("Cubic");

int main(int argc, char **argv)
{
    for (auto iter = RTStable.begin(); iter != RTStable.end(); ++iter)
    {
        std::cout << " *key:" << iter->first << std::endl;
    }
    float x;
    std::string choice;
    x = 3;
    std::cout << "select method(Sqr or Sqrt  or Cubic): " << std::endl;
    std::cin >> choice;
    std::cout << "Input Value: " << x << std::endl;
    // logic part
    std::cout << "Function call: " << RTStable[choice](x) << std::endl;

    return 0;
}