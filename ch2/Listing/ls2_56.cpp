#include <stdio.h>

#define FACTORY(token)                               \
    void token##Factory()                            \
    {                                                \
        printf("this is function for %s\n", #token); \
    }

FACTORY(openfoam)
FACTORY(int)
FACTORY(double)
int main()

{
    openfoamFactory();
    intFactory();
    doubleFactory();
    return 0;
}