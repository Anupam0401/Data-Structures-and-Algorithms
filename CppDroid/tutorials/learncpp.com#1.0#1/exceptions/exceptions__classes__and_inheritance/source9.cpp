class Base
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

int main()
{
    try
    {
        throw Derived();
    }
    catch (Base &cBase)
    {
        cerr << "caught Base";
    }
    catch (Derived &cDerived)
    {
        cerr << "caught Derived";
    }

    return 0;
}