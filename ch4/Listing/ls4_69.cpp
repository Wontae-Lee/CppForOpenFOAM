#include <map>
#include <string>

std::map<std::string, Record> recordTable;
std::map<std::string, void (*)(int)> callbackTable;