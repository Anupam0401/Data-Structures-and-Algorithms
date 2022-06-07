class Base
{
public:
    int m_nValue;
};

class Derived: public Base
{
private:
    Base::m_nValue;

public:
    Derived(int nValue)
    {
         m_nValue = nValue;
    }
};

int main()
{
    Derived cDerived(7);

    // The following won't work because m_nValue has been redefined as private
    cout << cDerived.m_nValue;

    return 0;
}