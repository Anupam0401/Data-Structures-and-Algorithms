class Base
{
protected:
    int m_nValue;

public:
    Base(int nValue)
        : m_nValue(nValue)
    {
    }

    const char* GetName() { return "Base"; }
    int GetValue() { return m_nValue; }
};

class Derived: public Base
{
public:
    Derived(int nValue)
        : Base(nValue)
    {
    }

    const char* GetName() { return "Derived"; }
    int GetValueDoubled() { return m_nValue * 2; }
};