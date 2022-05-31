#include <fstream>

int main()
{
    std::ifstream ifp{"test.txt"};
    int a;
    ifp >> a;
    ifp.close();

    return 0;
}