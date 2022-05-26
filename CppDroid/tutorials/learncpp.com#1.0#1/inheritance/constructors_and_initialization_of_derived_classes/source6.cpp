class Derived: public Base
{
public:
    double m_dValue;

    Derived(double dValue=0.0, int nValue=0)
        : Base(nValue), // Call Base(int) constructor with value nValue!
            m_dValue(dValue)
    {
    }
};