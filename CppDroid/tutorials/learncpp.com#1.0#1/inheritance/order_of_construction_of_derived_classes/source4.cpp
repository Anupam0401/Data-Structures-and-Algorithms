#include <iostream>
using namespace std;

class Base
{
public:
    int m_nValue;

    Base(int nValue=0)
        : m_nValue(nValue)
    {
        cout << "Base" << endl;
    }
};

class Derived: public Base
{
public:
    double m_dValue;

    Derived(double dValue=0.0)
        : m_dValue(dValue)
    {
        cout << "Derived" << endl;
    }
};

int main()
{
    cout << "Instantiating Base" << endl;
    Base cBase;

    cout << "Instantiating Derived" << endl;
    Derived cDerived;

    return 0;
}