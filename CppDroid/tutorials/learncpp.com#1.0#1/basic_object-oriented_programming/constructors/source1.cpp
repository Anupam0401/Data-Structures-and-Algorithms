class Fraction
{
private:
    int m_nNumerator;
    int m_nDenominator;

public:
    Fraction() // default constructor
    {
         m_nNumerator = 0;
         m_nDenominator = 1;
    }

    int GetNumerator() { return m_nNumerator; }
    int GetDenominator() { return m_nDenominator; }
    double GetFraction() { return static_cast<double>(m_nNumerator) / m_nDenominator; }
};