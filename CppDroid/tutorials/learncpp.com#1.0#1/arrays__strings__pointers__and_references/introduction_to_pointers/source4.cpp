int nValue = 5;
double dValue = 7.0;

int *pnPtr = &nValue; // ok
double *pdPtr = &dValue; // ok
pnPtr = &dValue; // wrong -- int pointer can not point to double value
pdPtr = &nValue; // wrong -- double pointer can not point to int value