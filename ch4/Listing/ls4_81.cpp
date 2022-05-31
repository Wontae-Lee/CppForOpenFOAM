class superClass
{
public:
    virtual ~superClass() {}
};

class subClass : public superClass
{
};

int main()
{
    superClass *super = new superClass{};
    subClass *sub = dynamic_cast<subClass *>(super);

    return 0;
}