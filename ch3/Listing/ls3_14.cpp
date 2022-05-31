#include <map>
#include <string>
#include <iostream>
int main()
{
    std::map<std::string, double> hashTable;

    // 삽입
    hashTable.insert(std::pair("cat", 4));
    hashTable.insert(std::pair("dog", 5));

    // 삭제
    hashTable.erase("cat");
    hashTable.erase("dog");

    for (auto iter = hashTable.begin(); iter != hashTable.end(); ++iter)
    {
        std::cout << iter->first << " , " << iter->second << std::endl;
    }

    return 0;
}