int g_anArray[10]; // a global array of 10 characters

#include <cassert> // for assert()
int GetArrayValue(int nIndex)
{
    // we're asserting that nIndex is between 0 and 9
    assert(nIndex >= 0 && nIndex <= 9); // this is line 7 in Test.cpp

    return g_anArray[nIndex];
}