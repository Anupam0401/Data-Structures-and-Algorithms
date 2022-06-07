class Date
{
private:
    int m_nMonth;
    int m_nDay;
    int m_nYear;

    Date() { } // private default constructor

public:
    Date(int nMonth, int nDay, int nYear);

    void SetDate(int nMonth, int nDay, int nYear);

    int GetMonth() { return m_nMonth; }
    int GetDay()  { return m_nDay; }
    int GetYear() { return m_nYear; }
};

// Date constructor
Date::Date(int nMonth, int nDay, int nYear)
{
    SetDate(nMonth, nDay, nYear);
}

// Date member function
void Date::SetDate(int nMonth, int nDay, int nYear)
{
    m_nMonth = nMonth;
    m_nDay = nDay;
    m_nYear = nYear;
}