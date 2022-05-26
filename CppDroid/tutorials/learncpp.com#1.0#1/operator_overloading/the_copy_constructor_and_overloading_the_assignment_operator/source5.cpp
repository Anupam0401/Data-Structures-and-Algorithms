class Cents
{
private:
    int m_nCents;
public:
    Cents(int nCents=0)
    {
        m_nCents = nCents;
    }

    // Copy constructor
    Cents(const Cents &cSource)
    {
        m_nCents = cSource.m_nCents;
    }

    Cents& operator= (const Cents &cSource);

};

Cents& Cents::operator= (const Cents &cSource)
{
    // do the copy
    m_nCents = cSource.m_nCents;

    // return the existing object
    return *this;
}