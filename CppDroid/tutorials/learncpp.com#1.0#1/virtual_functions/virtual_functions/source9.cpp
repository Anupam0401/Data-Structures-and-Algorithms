class Base
{
public:
    virtual int GetValue() { return 5; }
};

class Derived: public Base
{
public:
    virtual double GetValue() { return 6.78; }
};