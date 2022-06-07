char *pchValue; // chars are 1 byte
int *pnValue; // ints are usually 4 bytes
struct Something
{
    int nX, nY, nZ;
};
Something *psValue; // Something is probably 12 bytes

cout << sizeof(pchValue) << endl; // prints 4
cout << sizeof(pnValue) << endl; // prints 4
cout << sizeof(psValue) << endl; // prints 4