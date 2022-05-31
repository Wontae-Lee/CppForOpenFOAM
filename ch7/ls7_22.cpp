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
    SqrAddToTable()
    {
        RTStable.insert(std::pair<std::string, function1Ptr>("Sqr", Sqr));

        // list hash table
        std::cout << "Sqr inserted to table" << std::endl;
        for (auto iter = RTStable.begin(); iter != RTStable.end(); ++iter)
        {
            std::cout << "  *key: " << iter->first << std::endl;
        }
    }
};

class SqrtAddToTable
{
public:
    SqrtAddToTable()
    {
        RTStable.insert(std::pair<std::string, function1Ptr>("Sqrt", Sqrt));

        // list hash table
        std::cout << "Sqrt inserted to table" << std::endl;
        for (auto iter = RTStable.begin(); iter != RTStable.end(); ++iter)
        {
            std::cout << "  *key: " << iter->first << std::endl;
        }
    }
};

class CubicAddToTable
{
public:
    CubicAddToTable()
    {
        RTStable.insert(std::pair<std::string, function1Ptr>("Cubic", Cubic));

        // list hash table
        std::cout << "Sqrt inserted to table" << std::endl;
        for (auto iter = RTStable.begin(); iter != RTStable.end(); ++iter)
        {
            std::cout << "  *key: " << iter->first << std::endl;
        }
    }
};

SqrAddToTable SqrDelegator;
SqrtAddToTable SqrtDelegator;
CubicAddToTable CubicDelegator;

int main(int argc, char **argv)
{
    // register algorithm
    // RTStable.insert(std::make_pair("Sqr" , Sqr));
    // RTStable.insert(std::make_pair("Sqrt" , Sqrt));
    // RTStable.insert(std::make_pair("Cubic" , Cubic));

    float x;
    std::string choice;
    x = 3;
    // input part
    std::cout << "select method(Sqr or Sqrt  or Cubic): " << std::endl;
    std::cin >> choice;
    std::cout << "Input Value: " << x << std::endl;
    // logic part
    std::cout << "Function call: " << RTStable[choice](x) << std::endl;
    return 0;
}