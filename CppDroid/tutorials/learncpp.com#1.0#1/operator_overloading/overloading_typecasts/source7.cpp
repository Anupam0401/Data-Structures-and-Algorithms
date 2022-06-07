class Dollars
{
private:
    int m_nDollars;
public:
    Dollars(int nDollars=0)
    {
        m_nDollars = nDollars;
    }

     // Allow us to convert Dollars into Cents
     operator Cents() { return Cents(m_nDollars * 100); }
};