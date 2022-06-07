class Base
{
    virtual void A(float=0.0);
    virtual void B() const;
    virtual void C();
    void D();
};

class Derived: public Base
{
    virtual void A(int=0) override; // compile error because Derived::A(int) does not override Base::A(float)
    virtual void B() override; // compile error because Derived::B() does not override Base::B() const
    virtual void C() override; // ok!  Derived::C() overrides Base::C()
    void D() override; // compile error because Derived::D() does not override Base::D()
};