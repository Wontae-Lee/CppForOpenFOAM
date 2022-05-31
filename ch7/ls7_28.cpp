#include <iostream>
#include <cmath>
#include <map>
#include <memory>
#include <string>

class Sqr
{
public:
    Sqr() = default;
};

class Sqrt
{
public:
    Sqrt() = default;
};

class Cubic
{
public:
    Cubic() = default;
};

std::unique_ptr<Sqr> Sqr_factory()
{
    std::cout << "sqr object created" << std::endl;
    return std::unique_ptr<Sqr>(new Sqr());
}
std::unique_ptr<Sqrt> Sqrt_factory()
{
    std::cout << "sqr object created" << std::endl;
    return std::unique_ptr<Sqrt>(new Sqrt());
}

std::unique_ptr<Cubic> Cubic_factory()
{
    std::cout << "sqr object created" << std::endl;
    return std::unique_ptr<Cubic>(new Cubic());
}

using SqrPtr = std::unique_ptr<Sqr> (*)();
using SqrtPtr = std::unique_ptr<Sqrt> (*)();
using CubicPtr = std::unique_ptr<Cubic> (*)();

std::map<std::string, SqrPtr> SqrRTStable;
std::map<std::string, SqrtPtr> SqrtRTStable;
std::map<std::string, CubicPtr> CubicRTStable;

class SqrAddToTable
{
public:
    SqrAddToTable(const std::string &name)
    {
        SqrRTStable.insert(std::pair<std::string, SqrPtr>(name, Sqr_factory));
    }
};

class SqrtAddToTable
{
public:
    SqrtAddToTable(const std::string &name)
    {
        SqrtRTStable.insert(std::pair<std::string, SqrtPtr>(name, Sqrt_factory));
    }
};
class CubicAddToTable
{
public:
    CubicAddToTable(const std::string &name)
    {
        CubicRTStable.insert(std::pair<std::string, CubicPtr>(name, Cubic_factory));
    }
};

SqrAddToTable SqrDelegator("Sqr");
SqrtAddToTable SqrtDelegator("Sqrt");
CubicAddToTable CubicDelegator("Cubic");

int main(int argc, char **argv)
{
    std::cout << "SqrRTStable" << std::endl;
    for (auto iter = SqrRTStable.begin(); iter != SqrRTStable.end(); ++iter)
    {
        std::cout << " *key: " << iter->first << " -> ";
        iter->second();
    }
    std::cout << "SqrtRTStable" << std::endl;
    for (auto iter = SqrtRTStable.begin(); iter != SqrtRTStable.end(); ++iter)
    {
        std::cout << " *key: " << iter->first << " -> ";
        iter->second();
    }
    std::cout << "CubicRTStable" << std::endl;
    for (auto iter = CubicRTStable.begin(); iter != CubicRTStable.end(); ++iter)
    {
        std::cout << " *key: " << iter->first << " -> ";
        iter->second();
    }

    return 0;
}
