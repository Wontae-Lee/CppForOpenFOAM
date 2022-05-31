#include <vector>
#include <iostream>

int main()
{
    std::vector<double> doubleList;

    // 예비 메모리 크기 설정
    doubleList.reserve(1000);

    // 예비 메모리 크기확인
    std::cout << doubleList.capacity() << std::endl;

    // 데이터 크기 설정
    doubleList.resize(10);

    // 데이터 크기확인
    std::cout << doubleList.size() << std::endl;

    return 0;
}