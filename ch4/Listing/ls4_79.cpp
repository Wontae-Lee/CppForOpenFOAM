
int main()
{
    char str[] = "Lorem ipsum dolor sit amet";
    const char *cptr = str;

    char *ptr = const_cast<char *>(cptr);
    return 0;
}