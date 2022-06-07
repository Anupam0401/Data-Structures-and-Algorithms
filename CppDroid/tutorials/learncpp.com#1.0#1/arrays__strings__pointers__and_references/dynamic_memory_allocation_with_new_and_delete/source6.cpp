int nSize = 12;
int *pnArray = new int[nSize]; // note: nSize does not need to be constant!
pnArray[4] = 7;
delete[] pnArray;