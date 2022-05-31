#include <iostream>
#include <cmath>
#include <map>
#include <string>

double sqr(double x)
{
    std::cout << "sqr" << std::endl;
    return x * x;
}

double sqrt(double x)
{
    std::cout << "sqrt" << std::endl;
    return pow(x, 0.5);
}

double cubic(double x)
{
    std::cout << "cubic" << std::endl;
    return x * x * x;
}

int main(int argc, char **argv)
{
    using function1Ptr = double (*)(double x);

    std::map<std::string, function1Ptr> hashTable;
    hashTable.insert(std::pair<std::string, function1Ptr>("sqr", sqr));
    hashTable.insert(std::pair<std::string, function1Ptr>("sqrt", sqrt));
    hashTable.insert(std::pair<std::string, function1Ptr>("cubic", cubic));

    const char *choice = "sqr";
    double x = 3;
    auto result = hashTable[choice](x);
    std::cout << "result: " << result << std::endl;

    return 0;
}