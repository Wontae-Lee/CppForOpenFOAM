template <class T>
using std::map<std::string, T> TableType;

TableType<Record> recordTable;
TableType<void (*)(int)> callbackTable;
