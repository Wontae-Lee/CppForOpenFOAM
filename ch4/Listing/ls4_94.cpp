#include <list>
#include <iostream>

class myClass
{
public:
    myClass(std::initializer_list<int> l)
    {
        for (auto iter = l.begin(); iter != l.end(); ++iter)
        {
            std::cout << *iter << std::endl;
        }
    }
};