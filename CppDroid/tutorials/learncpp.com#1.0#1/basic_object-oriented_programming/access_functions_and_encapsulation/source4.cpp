class Change
{
private:
    int m_nValue;

public:
    void SetValue(int nValue) { m_nValue = nValue; }
    int GetValue() { return m_nValue; }
};

int main()
{
    Change cChange;
    cChange.SetValue(5);
    std::cout << cChange.GetValue() << std::endl;
}