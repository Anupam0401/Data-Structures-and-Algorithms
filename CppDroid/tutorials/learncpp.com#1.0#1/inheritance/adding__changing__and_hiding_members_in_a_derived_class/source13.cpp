class Derived: public Base
{
public:
    Derived(int nValue)
        : Base(nValue)
    {
    }

    // Base::PrintValue was inherited as protected, so the public has no access
    // But we're changing it to public by declaring it in the public section
    Base::PrintValue;
};