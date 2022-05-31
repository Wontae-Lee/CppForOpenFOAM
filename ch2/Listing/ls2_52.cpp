
#include <string>
#include <iostream>

#define PARAINFO(parm, desc) parainfo(parm, #parm " :" desc)

void parainfo(std::string para, std::string info)
{
    std::cout << info << std::endl;
}

int main()
{
    std::string debug{"debug"};
    PARAINFO(debug, "Debug level (0-4)");
    return 0;
}