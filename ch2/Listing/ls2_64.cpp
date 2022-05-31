
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifp("test.bin", std::ios::binary);
    int i;
    ifp.read(reinterpret_cast<char *>(&i), sizeof(int));
    std::cout << i << std::endl;

    ifp.close();
    return 0;
}