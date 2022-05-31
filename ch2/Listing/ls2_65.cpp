#include <fstream>

int main()
{
    std::ofstream ofp("test.txt");
    int a;
    ofp << a;
    ofp.close();
    return 0;
}