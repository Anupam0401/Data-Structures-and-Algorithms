struct Something
{
    int nValue;
    float fValue;
};

// Member selection using actual struct variable
Something sSomething;
sSomething.nValue = 5;

// Member selection using reference to struct
Something &rsSomething = sSomething;
rsSomething.nValue = 5;

// Member selection using pointer to struct
Something *psSomething = &sSomething;
(*psSomething).nValue = 5;