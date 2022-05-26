int *pnValue = new int;
*pnValue = 7;
delete pnValue;
pnValue = 0;

if (pnValue)
    *pnValue = 5;