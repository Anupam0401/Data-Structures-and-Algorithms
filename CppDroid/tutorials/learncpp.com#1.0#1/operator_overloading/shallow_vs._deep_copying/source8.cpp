// Copy constructor
MyString::MyString(const MyString& cSource)
{
    // because m_nLength is not a pointer, we can shallow copy it
    m_nLength = cSource.m_nLength;

    // m_pchString is a pointer, so we need to deep copy it if it is non-null
    if (cSource.m_pchString)
    {
        // allocate memory for our copy
        m_pchString = new char[m_nLength];

        // Copy the string into our newly allocated memory
        strncpy(m_pchString, cSource.m_pchString, m_nLength);
    }
    else
        m_pchString = 0;
}