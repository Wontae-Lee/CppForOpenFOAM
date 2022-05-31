template <typename T>
T add(T a, T b)
{
    return a + b;
}

// 템플릿 특수화
char *add(char *a, char *b)
{
    char *str = "string operation is not allowed";
    return str;
}