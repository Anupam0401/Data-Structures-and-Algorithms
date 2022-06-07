class Cents
{
private:
    int m_nCents;
public:
    Cents(int nCents)
        : m_nCents(nCents)
    {
    }

    friend ostream& operator<< (ostream &out, const Cents &cCents)
    {
        out << cCents.m_nCents << " cents ";
        return out;
    }
};