class Something
{
public:
    int m_nValue;

    const int& GetValue() const { return m_nValue; }
    int& GetValue() { return m_nValue; }
};