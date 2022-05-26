// Problematic assignment operator
MyString& MyString::operator=(const MyString& cSource)
{
    // Note: No check for self-assignment!

    // first we need to deallocate any value that this string is holding!
    delete[] m_pchString;

    // because m_nLength is not a pointer, we can shallow copy it
    m_nLength = cSource.m_nLength;

    // now we need to deep copy m_pchString
    if (cSource.m_pchString)
    {
        // allocate memory for our copy
        m_pchString = new char[m_nLength];

        // Copy the parameter the newly allocated memory
        strncpy(m_pchString, cSource.m_pchString, m_nLength);
    }
    else
        m_pchString = 0;

    return *this;
}