#include <string>
#include <iostream>
#include <math.h>
#include <map>
#include <memory>

class Function1
{
public:
    Function1() = default;

    virtual float operator()(float x) = 0;

    static constexpr char *typeName_ = "Function1";
    static const std::string typeName;
};
class Sqr : public Function1
{
public:
    Sqr() = default;

    virtual float operator()(float x)
    {
        std::cout << "sqr function called" << std::endl;
        return x * x;
    }
    static constexpr char *typeName_ = "Sqr";
    static const std::string typeName;
};
class Sqrt : public Function1
{
public:
    Sqrt() = default;

    virtual float operator()(float x)
    {
        std::cout << "sqrt function called" << std::endl;
        return std::pow(x, 0.5);
    }
    static constexpr char *typeName_ = "Sqrt";
    static const std::string typeName;
};
class Cubic : public Function1
{
public:
    Cubic() = default;

    virtual float operator()(float x)
    {
        std::cout << "cubic function called" << std::endl;
        return x * x * x;
    }
    static constexpr char *typeName_ = "Cubic";
    static const std::string typeName;
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

const std::string Function1::typeName = "Function1";
const std::string Sqr::typeName = "Sqr";
SqrAddToTable SqrDelegator;
const std::string Sqr::typeName = "Sqrt";
SqrAddToTable SqrDelegator;
const std::string Sqr::typeName = "Cubic";
SqrAddToTable SqrDelegator;

int main(int argc, char **argv)
{
    std::cout << "Function1RTStable" << std::endl;

    for (auto iter = Function1RTStable.begin(); iter != Function1RTStable.end(); ++iter)
    {
        std::cout << " *key: " << iter->first << " -> ";
        iter->second();
    }

    float x;
    std::string choice;
    x = 3;
    std::cout << "select method(Sqr or Sqrt  or Cubic): " << std::endl;
    std::cin >> choice;
    std::cout << "Input Value: " << x << std::endl;
    // logic part
    std::unique_ptr<Function1> func = Function1RTStable[choice]();
    std::cout << "Function call: " << (*func)(x) << std::endl;

    return 0;
}
