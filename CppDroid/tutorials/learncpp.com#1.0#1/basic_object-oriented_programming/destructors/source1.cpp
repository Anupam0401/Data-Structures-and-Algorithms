class MyString
{
private:
    char *m_pchString;
    int m_nLength;

public:
    MyString(const char *pchString="")
    {
        // Find the length of the string
        // Plus one character for a terminator
        m_nLength = strlen(pchString) + 1;

        // Allocate a buffer equal to this length
        m_pchString = new char[m_nLength];

        // Copy the parameter into our internal buffer
        strncpy(m_pchString, pchString, m_nLength);

        // Make sure the string is terminated
        m_pchString[m_nLength-1] = '\0';
    }

    ~MyString() // destructor
    {
        // We need to deallocate our buffer
        delete[] m_pchString;

        // Set m_pchString to null just in case
        m_pchString = 0;
    }

    char* GetString() { return m_pchString; }
    int GetLength() { return m_nLength; }
};