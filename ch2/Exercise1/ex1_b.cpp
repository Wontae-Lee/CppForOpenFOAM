#include <stdio.h>

int main(int argc, char **argv)
{

    printf("number of args: %d\n", argc);
    for (int i = 0; i < argc; ++i)
    {
        printf("%d th arg : %s\n", i, argv[i]);
    }
    return 0;
}