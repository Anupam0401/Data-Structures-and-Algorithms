class IntList
{
private:
    int m_anList[10];

public:
    void SetItem(int nIndex, int nData) { m_anList[nIndex] = nData; }
    int GetItem(int nIndex) { return m_anList[nIndex]; }
};