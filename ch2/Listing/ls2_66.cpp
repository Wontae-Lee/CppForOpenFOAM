

#include <fstream>

int main()
{
    std::ofstream ofp("test.bin", std::ios::binary);
    int i = 10;

    char buffer[27] = "Lorem ipsum dolor sit amet";

    ofp.write(buffer, 26);
    ofp.write(reinterpret_cast<char *>(&i), sizeof(int));

    ofp.close();
}