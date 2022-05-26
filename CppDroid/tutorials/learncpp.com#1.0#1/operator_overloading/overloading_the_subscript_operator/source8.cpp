#include <cassert> // for assert()

class IntList
{
private:
    int m_anList[10];

public:
    int& operator[] (const int nIndex);
};

int& IntList::operator[] (const int nIndex)
{
    assert(nIndex >= 0 && nIndex < 10);

    return m_anList[nIndex];
}