
void strcpy() {}

class Person
{
public:
    void test() {}
};

void Person::test()
{
    ::strcpy();
}