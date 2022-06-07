int nValue;
float fValue;

struct Something
{
    int nValue;
    float fValue;
};

Something sValue;

void *pVoid;
pVoid = &nValue; // valid
pVoid = &fValue; // valid
pVoid = &sValue; // valid