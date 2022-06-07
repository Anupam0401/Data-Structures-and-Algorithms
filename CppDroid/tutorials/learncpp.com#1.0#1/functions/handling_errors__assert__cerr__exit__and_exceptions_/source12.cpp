int g_anArray[10]; // a global array of 10 characters

int GetArrayValue(int nIndex)
{
    // use if statement to detect violated assumption
    if (nIndex < 0 || nIndex > 9)
       return -1; // return error code to caller

    return g_anArray[nIndex];
}