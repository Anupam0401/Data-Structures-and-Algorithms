class Cents
{
private:
    int m_nCents;

public:
    Cents(int nCents) { m_nCents = nCents; }

    // Overload cCents + int
    friend Cents operator+(const Cents &cCents, int nCents);

    // Overload int + cCents
    friend Cents operator+(int nCents, const Cents &cCents);

    int GetCents() { return m_nCents; }
};

// note: this function is not a member function!
Cents operator+(const Cents &cCents, int nCents)
{
    return Cents(cCents.m_nCents + nCents);
}

// note: this function is not a member function!
Cents operator+(int nCents, const Cents &cCents)
{
    return Cents(cCents.m_nCents + nCents);
}

int main()
{
    Cents c1 = Cents(4) + 6;
    Cents c2 = 6 + Cents(4);
    std::cout << "I have " << c1.GetCents() << " cents." << std::endl;
    std::cout << "I have " << c2.GetCents() << " cents." << std::endl;

    return 0;
}