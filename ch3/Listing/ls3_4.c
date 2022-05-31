#include <stdlib.h>

int main()
{
    //변수 선언
    double *doubleList;
    // array 크기
    int size = 10;
    // 메모리할당
    doubleList = (double *)malloc(sizeof(double) * size);
    // 메모리해제
    free(doubleList);
    return 0;
}