#include <map>
#include <string>

int main()
{
    std::map<std::string, double> hashTable;

    // 삽입
    hashTable.insert(std::pair("cat", 4));
    hashTable.insert(std::pair("dog", 5));

    // 삭제
    hashTable.erase("cat");
    hashTable.erase("dog");

    return 0;
}