class Base
{
public:
    virtual const char* GetName() { return "Base"; }
};

class Derived: public Base
{
public
    virtual const char* GetName() { return "Derived"; }
};