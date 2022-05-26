class Base
{
public:
    int m_nValue;

    Base(int nValue=0)
        : m_nValue(nValue)
    {
    }
};

class Derived: public Base
{
public:
    double m_dValue;

    Derived(double dValue=0.0)
        : m_dValue(dValue)
    {
    }
};