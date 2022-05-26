int g_anArray[10]; // a global array of 10 characters

int GetArrayValue(int nIndex)
{
    // use if statement to detect violated assumption
    if (nIndex < 0 || nIndex > 9)
       exit(2); // terminate program and return error number 2 to OS

    return g_anArray[nIndex];
}