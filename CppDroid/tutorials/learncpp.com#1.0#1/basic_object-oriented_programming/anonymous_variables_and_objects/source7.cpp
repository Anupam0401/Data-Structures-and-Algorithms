class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    int GetCents() { return m_nCents; }
};

Cents Add(Cents &c1, Cents &c2)
{
    return Cents(c1.GetCents() + c2.GetCents());
}

int main()
{
    Cents cCents1(6);
    Cents cCents2(8);
    std::cout << "I have " << Add(cCents1, cCents2).GetCents() << " cents." << std::endl;

    return 0;
}