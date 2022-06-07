class Access
{
   int m_nA; // private by default
   int GetA() { return m_nA; } // private by default

private:
   int m_nB; // private
   int GetB() { return m_nB; } // private

protected:
   int m_nC; // protected
   int GetC() { return m_nC; } // protected

public:
   int m_nD; // public
   int GetD() { return m_nD; } // public

};

int main()
{
    Access cAccess;
    cAccess.m_nD = 5; // okay because m_nD is public
    std::cout << cAccess.GetD(); // okay because GetD() is public

    cAccess.m_nA = 2; // WRONG because m_nA is private
    std::cout << cAccess.GetB(); // WRONG because GetB() is private

    return 0;
}