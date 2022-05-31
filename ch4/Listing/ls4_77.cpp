template <class Type>
class CRTP;

class Derived : public CRTP<Derived>
{
    //
}