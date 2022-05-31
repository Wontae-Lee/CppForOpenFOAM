#include <iostream>

class A
{
public:
    int memberVar;
    static int classVar;
};

int A::classVar = 1;
int main(int argc, char **argv)
{
    A a;
    a.memberVar = 0;
    std::cout << "member variable of A: " << a.memberVar << std::endl;
    std::cout << "class variable of A: " << A::classVar << std::endl;

    A::classVar = 2;
    std::cout << "class variable of A: " << A::classVar << std::endl;
    return 0;
}
