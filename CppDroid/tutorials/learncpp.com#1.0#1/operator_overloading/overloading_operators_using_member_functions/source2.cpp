class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    // Overload -cCents
    Cents operator-();
};

// note: this function is a member function!
Cents Cents::operator-()
{
    return Cents(-m_nCents);
}