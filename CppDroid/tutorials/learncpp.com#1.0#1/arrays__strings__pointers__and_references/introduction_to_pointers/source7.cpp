int nValue1 = 5;
int nValue2 = 7;

int *pnPtr;

pnPtr = &nValue1; // pnPtr points to nValue1
cout << *pnPtr; // prints 5

pnPtr = &nValue2; // pnPtr now points to nValue2
cout << *pnPtr; // prints 7