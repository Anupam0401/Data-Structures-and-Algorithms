class Calc
{
private:
    int m_nValue;

public:
    Calc() { m_nValue = 0; }

    void Add(int nValue) { m_nValue += nValue; }
    void Sub(int nValue) { m_nValue -= nValue; }
    void Mult(int nValue) { m_nValue *= nValue; }

    int GetValue() { return m_nValue; }
};