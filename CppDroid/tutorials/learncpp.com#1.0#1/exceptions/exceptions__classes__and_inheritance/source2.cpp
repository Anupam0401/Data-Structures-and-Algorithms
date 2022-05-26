int IntArray::operator[](const int nIndex)
{
    assert (nIndex >= 0 && nIndex < GetLength());
    return m_nData[nIndex];
}