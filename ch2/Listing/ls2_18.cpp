

int main()
{
    int num1 = 1;
    int num2 = 2;
    const int *pNum = &num1;

    // *pNum = 9; // compile error because target it read-only

    return 0;
}