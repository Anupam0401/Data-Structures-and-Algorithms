#include <iostream>

int nFive = 5;
int nSix = 6;

// Function prototype so we can define
// SetToSix below main()
void SetToSix(int *pTempPtr);

int main()
{
    using namespace std;

    // First we set pPtr to the address of nFive
    // Which means *pPtr = 5
    int *pPtr = &nFive;

    // This will print 5
    cout << *pPtr;

    // Now we call SetToSix (see function below)
    // pTempPtr receives a copy of the address of pPtr
    SetToSix(pPtr);

    // pPtr is still set to the address of nFive!
    // This will print 5
    cout << *pPtr;

    return 0;
}

// pTempPtr copies the value of pPtr!
void SetToSix(int *pTempPtr)
{
    using namespace std;

    // This only changes pTempPtr, not pPtr!
    pTempPtr = &nSix;

    // This will print 6
    cout << *pTempPtr;
}