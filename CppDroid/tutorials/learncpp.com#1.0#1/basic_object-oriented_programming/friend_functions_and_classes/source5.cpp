class Storage
{
private:
    int m_nValue;
    double m_dValue;
public:
    Storage(int nValue, double dValue)
    {
        m_nValue = nValue;
        m_dValue = dValue;
    }

    // Make the Display class a friend of Storage
    friend class Display;
};

class Display
{
private:
    bool m_bDisplayIntFirst;

public:
    Display(bool bDisplayIntFirst) { m_bDisplayIntFirst = bDisplayIntFirst; }

    void DisplayItem(Storage &cStorage)
    {
        if (m_bDisplayIntFirst)
            std::cout << cStorage.m_nValue << " " << cStorage.m_dValue << std::endl;
        else // display double first
            std::cout << cStorage.m_dValue << " " << cStorage.m_nValue << std::endl;
    }
};