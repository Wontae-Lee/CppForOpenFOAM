

int main()
{
    int num1 = 1;
    int num2 = 2;
    int *const pNum = &num1;

    *pNum = 9;

    return 0;
}