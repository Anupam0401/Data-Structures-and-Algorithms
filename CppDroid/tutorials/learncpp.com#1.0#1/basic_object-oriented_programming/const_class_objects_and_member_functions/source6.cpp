class Something
{
public:
    int m_nValue;

    Something() { m_nValue = 0; }

    void ResetValue() { m_nValue = 0; }
    void SetValue(int nValue) { m_nValue = nValue; }

    int GetValue() const;
};

int Something::GetValue() const
{
    return m_nValue;
}