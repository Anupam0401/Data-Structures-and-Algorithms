#include <cassert>
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

    // Constructor with parameters
    Fraction(int nNumerator, int nDenominator=1)
    {
        assert(nDenominator != 0);
        m_nNumerator = nNumerator;
        m_nDenominator = nDenominator;
    }

    int GetNumerator() { return m_nNumerator; }
    int GetDenominator() { return m_nDenominator; }
    double GetFraction() { return static_cast<double>(m_nNumerator) / m_nDenominator; }
};