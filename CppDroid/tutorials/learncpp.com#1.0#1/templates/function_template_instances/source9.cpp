class Cents
{
private:
    int m_nCents;
public:
    Cents(int nCents)
        : m_nCents(nCents)
    {
    }

    friend bool operator>(Cents &c1, Cents&c2)
    {
        return (c1.m_nCents > c2.m_nCents) ? true: false;
    }
};