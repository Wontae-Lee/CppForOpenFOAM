#include <map>
#include <string>

typedef std::map<std::string, Record> TableType1;
typedef std::map<std::string, void(*) int> TableType2;
TableType1 recordTable;
TableType2 TableType2;
