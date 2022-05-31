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

std::unique_ptr<Sqr> Sqr_factory()
{
    std::cout << "sqr object created" << std::endl;
    return std::unique_ptr<Sqr>(new Sqr());
}

using SqrPtr = std::unique_ptr<Sqr> (*)();
std::map<std::string, SqrPtr> SqrRTStable;

class SqrAddToTable
{
public:
    SqrAddToTable(const std::string &name)
    {
        SqrRTStable.insert(std::pair<std::string, SqrPtr>(name, Sqr_factory));
    }
};

SqrAddToTable SqrDelegator("Sqr");
int main(int argc, char **argv)
{
    std::cout << "SqrRTStable" << std::endl;
    for (auto iter = SqrRTStable.begin(); iter != SqrRTStable.end(); ++iter)
    {
        std::cout << " *key: " << iter->first << " -> ";
        iter->second();
    }

    return 0;
}