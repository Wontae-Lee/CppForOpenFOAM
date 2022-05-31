template <class T>
typedef std::map<std::string, T> TableType;

TableType<Record> recordTable;
TableType<void (*)(int)> callbackTable;
