class Derived: public Base
{
public:
    Derived(int nValue)
        :Base(nValue)
    {
    }

    int GetValue() { return m_nValue; }

    // Here's our modified function
    void Identify() { cout << "I am a Derived" << endl; }
};