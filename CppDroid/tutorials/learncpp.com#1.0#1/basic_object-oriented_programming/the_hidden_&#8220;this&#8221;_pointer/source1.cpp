class Simple
{
private:
    int m_nID;

public:
    Simple(int nID)
    {
        SetID(nID);
    }

    void SetID(int nID) { m_nID = nID; }
    int GetID() { return m_nID; }
};