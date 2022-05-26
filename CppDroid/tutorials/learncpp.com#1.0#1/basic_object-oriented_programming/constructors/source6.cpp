#include <cassert>
class Fraction
{
private:
    int m_nNumerator;
    int m_nDenominator;

public:
    // Default constructor
    Fraction(int nNumerator=0, int nDenominator=1)
    {
        assert(nDenominator != 0);
        m_nNumerator = nNumerator;
        m_nDenominator = nDenominator;
    }

    int GetNumerator() { return m_nNumerator; }
    int GetDenominator() { return m_nDenominator; }
    double GetFraction() { return static_cast<double>(m_nNumerator) / m_nDenominator; }
};