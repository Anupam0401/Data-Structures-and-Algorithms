class Base final // final identifier marks this class as non-inheritable
{
};

class Derived: public Base // trying to override final class Base will cause a compiler error
{
};