class Base
{
private:
    int m_nValue;

public:
    Base(int nValue)
        : m_nValue(nValue)
    {
    }

protected:
    void PrintValue() { cout << m_nValue; }
};