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
    catch (Derived &cDerived)
    {
        cerr << "caught Derived";
    }
    catch (Base &cBase)
    {
        cerr << "caught Base";
    }

    return 0;
}