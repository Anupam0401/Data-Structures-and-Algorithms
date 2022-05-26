class Derived: public Base
{
public:
    Derived(int nValue)
        :Base(nValue)
    {
    }

    int GetValue() { return m_nValue; }

    void Identify()
    {
        Base::Identify(); // call Base::Identify() first
        cout << "I am a Derived"; // then identify ourselves
    }
};