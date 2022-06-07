// Generate a random number between nLow and nHigh (inclusive)
unsigned int GetRandomNumber(int nLow, int nHigh)
{
    return (rand() % (nHigh - nLow + 1)) + nLow;
}