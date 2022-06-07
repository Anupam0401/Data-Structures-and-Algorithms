class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    // Overload cCents + int
    friend Cents operator+(Cents &cCents, int nCents);

    int GetCents() { return m_nCents; }
};

// note: this function is not a member function!
Cents operator+(Cents &cCents, int nCents)
{
    return Cents(cCents.m_nCents + nCents);
}