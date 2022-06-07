class String
{
private:
    char *m_chString; // a dynamically allocated string
    int m_nLength; // the length of m_chString

public:
    int GetLength() { return m_nLength; }
};