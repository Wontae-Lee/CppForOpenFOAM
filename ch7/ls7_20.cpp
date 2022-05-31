#include <iostream>
#include <map>

std::map<int, int> hashTable;

class addToTable {
 public:
  addToTable() {
    hashTable.insert(std::pair<int, int>(3, 5));

    for (auto iter = hashTable.begin(); iter != hashTable.end(); ++iter) {
      std::cout << "key: " << iter->first << " value: " << iter->second
                << std::endl;
    }
  }
};
addToTable globalObj;

int main(int argc, char** argv) { return 0; }