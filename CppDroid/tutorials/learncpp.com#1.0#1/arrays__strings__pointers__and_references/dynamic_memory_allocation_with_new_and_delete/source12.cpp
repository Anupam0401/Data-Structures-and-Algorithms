int *pnValue = new int;
delete pnValue; // pnValue not set to 0

if (pnValue)
    *pnValue = 5; // will cause a crash