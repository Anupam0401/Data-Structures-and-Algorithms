class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    // Overload -cCents
    friend Cents operator-(const Cents &cCents);
};

// note: this function is not a member function!
Cents operator-(const Cents &cCents)
{
    return Cents(-cCents.m_nCents);
}