void PrintArray(int *pnArray, int nLength)
{
    // if user passed in a null pointer for pnArray, bail out early!
    if (!pnArray)
        return;

    for (int iii=0; iii < nLength; iii++)
        cout << pnArray[iii] << endl;
}