#include <stdio.h>
#include <stdlib.h>

#define MAXBUFFER 256

int main(int argc, char **argv)
{
    FILE *fp = NULL;
    char line[MAXBUFFER];
    double time, era;
    fp = fopen("wave.csv", "r");
    fgets(line, MAXBUFFER, fp);

    while (fscanf(fp, "%lf, %lf", &time, &era) && !feof(fp))
    {
        printf("%lf %lf\n", time, era);
    }
    fclose(fp);
    return 0;
}