#include <iostream>
#define CONCAT(x, y) x##y

int main()
{
    std::cout << CONCAT(1, 2) << std::endl;
    return 0;
}