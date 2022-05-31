int main()
{
    int *intPtr = new int;

    double *doublePtr = new double[3];

    *intPtr = 1;        // dereference
    doublePtr[0] = 1.1; // dereference
    doublePtr[1] = 2.1; // dereference
    doublePtr[2] = 3.1; // dereference

    delete intPtr;      // 객체 메모리 해제
    delete[] doublePtr; // 배열 메모리 해제

    return 0;
}
