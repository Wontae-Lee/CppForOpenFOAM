class superClass
{
public:
    void feature1();
    void feature2();
};

class Subclass : public superClass
{
public:
    void feature3();
    void feature4();
};

void superClass::feature1() {}
void superClass::feature2() {}

void Subclass::feature3() {}
void Subclass::feature4() {}