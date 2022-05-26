class Date
{
private:
    int m_nMonth;
    int m_nDay;
    int m_nYear;
};

int main()
{
    Date cDate;
    // cDate's member variables now contain garbage
    // Who knows what date we'll get?

    return 0;
}