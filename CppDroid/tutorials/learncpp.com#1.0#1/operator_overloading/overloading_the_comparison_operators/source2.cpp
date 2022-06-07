class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    friend bool operator> (Cents &cC1, Cents &cC2);
    friend bool operator<= (Cents &cC1, Cents &cC2);

    friend bool operator< (Cents &cC1, Cents &cC2);
    friend bool operator>= (Cents &cC1, Cents &cC2);
};

bool operator> (Cents &cC1, Cents &cC2)
{
    return cC1.m_nCents > cC2.m_nCents;
}

bool operator<= (Cents &cC1, Cents &cC2)
{
    return cC1.m_nCents <= cC2.m_nCents;
}

bool operator< (Cents &cC1, Cents &cC2)
{
    return cC1.m_nCents < cC2.m_nCents;
}

bool operator>= (Cents &cC1, Cents &cC2)
{
    return cC1.m_nCents >= cC2.m_nCents;
}