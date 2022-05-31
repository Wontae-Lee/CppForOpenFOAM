#include <iostream>
#include <cmath>
#include <map>
#include <memory>
#include <string>

class Function1
{
public:
    Function1() = default;
};

class Sqr : public Function1
{
public:
    Sqr() = default;
};

class Sqrt : public Function1
{
public:
    Sqrt() = default;
};

class Cubic : public Function1
{
public:
    Cubic() = default;
};

std::unique_ptr<Function1> Sqr_factory()
{
    std::cout << "sqr object created" << std::endl;
    return std::unique_ptr<Function1>(new Sqr());
}
std::unique_ptr<Function1> Sqrt_factory()
{
    std::cout << "sqt object created" << std::endl;
    return std::unique_ptr<Function1>(new Sqrt());
}

std::unique_ptr<Function1> Cubic_factory()
{
    std::cout << "Cubic object created" << std::endl;
    return std::unique_ptr<Function1>(new Cubic());
}

using Function1Ptr = std::unique_ptr<Function1> (*)();

std::map<std::string, Function1Ptr> Function1RTStable;

class SqrAddToTable
{
public:
    SqrAddToTable(const std::string &name)
    {
        Function1RTStable.insert(std::pair<std::string, Function1Ptr>(name, Sqr_factory));
    }
};

class SqrtAddToTable
{
public:
    SqrtAddToTable(const std::string &name)
    {
        Function1RTStable.insert(std::pair<std::string, Function1Ptr>(name, Sqrt_factory));
    }
};
class CubicAddToTable
{
public:
    CubicAddToTable(const std::string &name)
    {
        Function1RTStable.insert(std::pair<std::string, Function1Ptr>(name, Cubic_factory));
    }
};

SqrAddToTable SqrDelegator("Sqr");
SqrtAddToTable SqrtDelegator("Sqrt");
CubicAddToTable CubicDelegator("Cubic");

int main(int argc, char **argv)
{
    std::cout << "Function1RTStable" << std::endl;

    for (auto iter = Function1RTStable.begin(); iter != Function1RTStable.end(); ++iter)
    {
        std::cout << " *key: " << iter->first << " -> ";
        iter->second();
    }

    return 0;
}
