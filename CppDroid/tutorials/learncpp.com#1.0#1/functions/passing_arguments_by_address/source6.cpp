// pTempPtr is now a reference to a pointer to pPtr!
// This means if we change pTempPtr, we change pPtr!
void SetToSix(int *&pTempPtr)
{
    using namespace std;

    pTempPtr = &nSix;

    // This will print 6
    cout << *pTempPtr;
}