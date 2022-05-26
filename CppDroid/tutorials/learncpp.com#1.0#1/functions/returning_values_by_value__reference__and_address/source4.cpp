int* DoubleValue(int nX)
{
    int nValue = nX * 2;
    return &nValue; // return nValue by address here
} // nValue goes out of scope here