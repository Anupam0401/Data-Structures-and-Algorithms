class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    // overload Cents + Cents
    friend Cents operator+(const Cents &c1, const Cents &c2);

    // overload Cents - Cents
    friend Cents operator-(const Cents &c1, const Cents &c2);

    int GetCents() { return m_nCents; }
};

// note: this function is not a member function!
Cents operator+(const Cents &c1, const Cents &c2)
{
    // use the Cents constructor and operator+(int, int)
    return Cents(c1.m_nCents + c2.m_nCents);
}

// note: this function is not a member function!
Cents operator-(const Cents &c1, const Cents &c2)
{
    // use the Cents constructor and operator-(int, int)
    return Cents(c1.m_nCents - c2.m_nCents);
}