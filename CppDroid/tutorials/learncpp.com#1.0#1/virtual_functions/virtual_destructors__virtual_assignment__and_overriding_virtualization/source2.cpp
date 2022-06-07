class Base
{
public:
    virtual ~Base()
    {
        cout << "Calling ~Base()" << endl;
    }
};

class Derived: public Base
{
private:
    int* m_pnArray;

public:
    Derived(int nLength)
    {
        m_pnArray = new int[nLength];
    }

    virtual ~Derived()
    {
        cout << "Calling ~Derived()" << endl;
        delete[] m_pnArray;
    }
};

int main()
{
    Derived *pDerived = new Derived(5);
    Base *pBase = pDerived;
    delete pBase;

    return 0;
}