class IntList
{
private:
    int m_anList[10];

public:
    int& operator[] (const int nIndex);
};

int& IntList::operator[] (const int nIndex)
{
    return m_anList[nIndex];
}