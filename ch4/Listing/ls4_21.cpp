#include <iostream>

using namespace std;
class Test
{
public:
    Test() { std::cout << "default constructor" << std::endl; }
    Test(const Test &t) { std::cout << "copy constructor" << std::endl; }
    Test &operator=(const Test &t)
    {
        cout << "assignment operator" << std::endl;
        return *this;
    }
};
int main()
{
    Test t1;
    Test t2(t1);
    Test t3 = t1;
    t1 = t2;
}
