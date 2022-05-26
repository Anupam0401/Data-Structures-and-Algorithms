template <class T>
Cents Average(Cents  *atArray, int nNumValues)
{
    Cents tSum = 0;
    for (int nCount=0; nCount < nNumValues; nCount++)
        tSum += atArray[nCount];

    tSum /= nNumValues;
    return tSum;
}