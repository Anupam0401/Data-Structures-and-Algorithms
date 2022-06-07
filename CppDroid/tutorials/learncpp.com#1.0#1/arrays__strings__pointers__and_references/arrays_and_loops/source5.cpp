const int nArraySize = 5;
int anArray[nArraySize ] = { 6, 8, 2, 4, 9 };
int nMaxValue = 0;
for (int nIndex = 0; nIndex <= nArraySize; nIndex++)
    if (anArray[nIndex] > nMaxValue)
        nMaxValue = anArray[nIndex];