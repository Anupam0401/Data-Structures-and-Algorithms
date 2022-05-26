class Calc
{
private:
    int m_nValue;

public:
    Calc() { m_nValue = 0; }

    void Add(int nValue);
    void Sub(int nValue);
    void Mult(int nValue);

    int GetValue() { return m_nValue; }
};

void Calc::Add(int nValue)
{
    m_nValue += nValue;
}

void Calc::Sub(int nValue)
{
    m_nValue -= nValue;
}

void Calc::Mult(int nValue)
{
    m_nValue *= nValue;
}