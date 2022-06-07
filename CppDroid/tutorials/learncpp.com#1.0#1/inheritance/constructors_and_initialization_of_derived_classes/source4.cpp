class Derived: public Base
{
public:
    double m_dValue;

    Derived(double dValue=0.0, int nValue=0)
        // does not work
        : m_dValue(dValue), m_nValue(nValue)
    {
    }
};