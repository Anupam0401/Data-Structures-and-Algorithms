class Digit
{
private:
    int m_nDigit;
public:
    Digit(int nDigit=0)
    {
        m_nDigit = nDigit;
    }

    Digit& operator++();
    Digit& operator--();

    int GetDigit() const { return m_nDigit; }
};

Digit& Digit::operator++()
{
    // If our number is already at 9, wrap around to 0
    if (m_nDigit == 9)
        m_nDigit = 0;
    // otherwise just increment to next number
    else
        ++m_nDigit;

    return *this;
}

Digit& Digit::operator--()
{
    // If our number is already at 0, wrap around to 9
    if (m_nDigit == 0)
        m_nDigit = 9;
    // otherwise just decrement to next number
    else
        --m_nDigit;

    return *this;
}