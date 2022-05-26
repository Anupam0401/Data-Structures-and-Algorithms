class Change
{
public:
    int m_nValue;
};

int main()
{
    Change cChange;
    cChange.m_nValue = 5;
    std::cout << cChange.m_nValue << std::endl;
};