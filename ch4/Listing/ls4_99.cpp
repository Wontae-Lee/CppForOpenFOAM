#include <iostream>

int sum_all() { return 0; }

template <typename... Ints>
int sum_all(int num, Ints... num)
{
    return num + sum_all(nums...);
}

int main()
{
    std::cout << sum_all(1, 4, 2, 3, 10) << std::endl;
    return 0;
}