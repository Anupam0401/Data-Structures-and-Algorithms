class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    // Overload cCents + int
    Cents operator+(int nCents);

    int GetCents() { return m_nCents; }
};

// note: this function is a member function!
Cents Cents::operator+(int nCents)
{
    return Cents(m_nCents + nCents);
}