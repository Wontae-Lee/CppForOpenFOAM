#include <iostream>

class addToTable {
 public:
  addToTable() { std::cout << "Did you call me?" << std::endl; }
};

addToTable globalObject;

int main(int argc, char** argv) { return 0; }