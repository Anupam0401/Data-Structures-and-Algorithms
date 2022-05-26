int IntArray::operator[](const int nIndex)
{
    if (nIndex < 0 || nIndex >= GetLength())
        throw nIndex;

    return m_nData[nIndex];
}