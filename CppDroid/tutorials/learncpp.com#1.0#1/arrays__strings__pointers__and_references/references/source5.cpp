int nValue = 5;
int nValue2 = 6;

int &rnRef = nValue;
rnRef = nValue2; // assigns value 6 to nValue -- does NOT change the reference!