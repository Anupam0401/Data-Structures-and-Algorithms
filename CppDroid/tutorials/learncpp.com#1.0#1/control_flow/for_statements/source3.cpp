// returns the value nBase ^ nExp
int Exponent(int nBase, int nExp)
{
    int nValue = 1;
    for (int iii=0; iii < nExp; iii++)
        nValue *= nBase;

    return nValue;
}