
int main()
{
    double value = 1.1;
    int ivalue = static_cast<int>(value);
    float fvalue = static_cast<int>(value);

    char str[] = "Lorem ipsum dolor sit amet";
    char *pstr = static_cast<char *>(str);

    return 0;
}