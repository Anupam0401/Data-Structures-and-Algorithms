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
    Cents cTemp(c1.GetCents() + c2.GetCents());
    return cTemp;
}

int main()
{
    Cents cCents1(6);
    Cents cCents2(8);
    Cents cCentsSum = Add(cCents1, cCents2);
    std::cout << "I have " << cCentsSum.GetCents() << " cents." << std::endl;

    return 0;
}