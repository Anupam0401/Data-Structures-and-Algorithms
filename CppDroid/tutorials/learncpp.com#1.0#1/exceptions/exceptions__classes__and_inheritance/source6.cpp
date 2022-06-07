int IntArray::operator[](const int nIndex)
{
    if (nIndex < 0 || nIndex >= GetLength())
        throw ArrayException("Invalid index");

    return m_nData[nIndex];
}