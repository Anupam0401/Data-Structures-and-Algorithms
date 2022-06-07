class Date
{
public:
    int m_nMonth; // public
    int m_nDay; // public
    int m_nYear; // public
};

int main()
{
    Date cDate;
    cDate.m_nMonth = 10; // okay because m_nMonth is public
    cDate.m_nDay = 14;  // okay because m_nDay is public
    cDate.m_nYear = 2020;  // okay because m_nYear is public

    return 0;
}