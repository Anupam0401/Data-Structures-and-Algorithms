class Base
{
protected:

public:
    virtual const char* GetName() { return "Base"; }
};

class Derived: public Base
{
public:
    const char* GetName() { return "Derived"; } // note lack of virtual keyword
};

int main()
{
    Derived cDerived;
    Base &rBase = cDerived;
    cout << "rBase is a " << rBase.GetName() << endl;

    return 0;
}