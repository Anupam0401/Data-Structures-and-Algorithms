int nValue = 5;
int *pnPtr = &nValue; // pnPtr points to nValue

*pnPtr = 7; // *pnPtr is the same as nValue, which is assigned 7
cout << nValue; // prints 7