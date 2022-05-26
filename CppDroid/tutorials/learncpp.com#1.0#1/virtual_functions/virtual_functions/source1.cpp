class Base
{
protected:

public:
    const char* GetName() { return "Base"; }
};

class Derived: public Base
{
public:
    const char* GetName() { return "Derived"; }
};

int main()
{
    Derived cDerived;
    Base &rBase = cDerived;
    cout << "rBase is a " << rBase.GetName() << endl;
}