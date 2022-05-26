class Simple
{
private:
    int m_nID;

public:
    Simple(int nID)
    {
        std::cout << "Constructing Simple " << nID<< std::endl;
        m_nID = nID;
    }

    ~Simple()
    {
        std::cout << "Destructing Simple" << m_nID << std::endl;
    }

    int GetID() { return m_nID; }
};

int main()
{
    // Allocate a Simple on the stack
    Simple cSimple(1);
    std::cout << cSimple.GetID() << std::endl;

    // Allocate a Simple dynamically
    Simple *pSimple = new Simple(2);
    std::cout << pSimple->GetID() << std::endl;
    delete pSimple;

    return 0;
} // cSimple goes out of scope here