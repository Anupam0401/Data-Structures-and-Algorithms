class Date
{
private:
    int m_nMonth;
    int m_nDay;
    int m_nYear;

public:
    Date(int nMonth=1, int nDay=1, int nYear=1970)
    {
        m_nMonth = nMonth;
        m_nDay = nDay;
        m_nYear = nYear;
    }
};

int main()
{
    Date cDate; // cDate is initialized to Jan 1st, 1970 instead of garbage

    Date cToday(9, 5, 2007); // cToday is initialized to Sept 5th, 2007

    return 0;
}