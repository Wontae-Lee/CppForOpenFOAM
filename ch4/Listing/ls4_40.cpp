class A
{
public:
    virtual ~A() = default;
    virtual void func() const;
    virtual void func(int x) const;
};

class B : public A
{
public:
    void func() const; // 슈퍼클래스에 오버로딩 함수가 보이지 않게된다.
};

int main(int argc, char **argv)
{
    B b;
    // b.func(123); // 슈퍼클래스에 오버로딩된 func(int) 가 보이지 않는다.
    return 0;
}