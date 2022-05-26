// return the sum of 1 to nValue
int SumTo(int nValue)
{
    if (nValue <=1)
        return nValue;
    else
        return SumTo(nValue - 1) + nValue;
}