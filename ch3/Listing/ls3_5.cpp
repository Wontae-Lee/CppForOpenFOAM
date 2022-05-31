int main()
{
    //변수 선언
    double *doubleList;

    // array 크기
    int size = 10;
    // 메모리할당
    doubleList = new double[size];
    // 메모리 해제
    delete[] doubleList;
    return 0;
}