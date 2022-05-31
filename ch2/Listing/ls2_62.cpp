#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI atan2(1., 1.) * 4

int main(int argc, char **argv)
{
    FILE *fp = NULL;

    double x, delx;

    fp = fopen("sine.csv", "w");
    delx = PI / 10;
    fprintf(fp, "time, sine \n");
    for (int i = 0; i < 11; ++i)
    {
        x = delx * i;
        fprintf(fp, "%lf, %lf\n", x, sin(x));
    }

    fclose(fp);
    return 0;
}