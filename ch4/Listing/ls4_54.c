int stateful(int i)
{
    static int state = 0;
    state = i;
    return i;
}