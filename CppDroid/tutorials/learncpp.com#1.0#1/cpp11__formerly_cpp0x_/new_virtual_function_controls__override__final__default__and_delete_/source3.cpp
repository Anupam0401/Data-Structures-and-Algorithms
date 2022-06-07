class Base
{
    virtual void A() final; // final identifier marks this function as non-overrideable
};

class Derived: public Base
{
    virtual void A(); // trying to override final function Base::A() will cause a compiler error
};