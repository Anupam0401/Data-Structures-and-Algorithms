#include <iostream>
using namespace std;

class Base
{
protected:
    int m_nValue;

public:
    Base(int nValue)
        : m_nValue(nValue)
    {
    }

    void Identify() { cout << "I am a Base" << endl; }
};