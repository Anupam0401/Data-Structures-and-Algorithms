class Date
{
private:
    int m_nMonth;
    int m_nDay;
    int m_nYear;

public:
    // Getters
    int GetMonth() { return m_nMonth; }
    int GetDay() { return m_nDay; }
    int GetYear() { return m_nYear; }

    // Setters
    void SetMonth(int nMonth) { m_nMonth = nMonth; }
    void SetDay(int nDay) { m_nDay = nDay; }
    void SetYear(int nYear) { m_nYear = nYear; }
};