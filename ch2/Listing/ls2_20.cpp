#include <iostream>

int func(int *__restrict__ a, int *__restrict__ b)
{
    int c{0};

    for (int i = 0; i < 10; ++i)
    {
        c = a[i] + b[i];
    }
    std::cout << c << std::endl;
}

int main()
{
    int array[20];
    func(array, array + 10);

    return 0;
}