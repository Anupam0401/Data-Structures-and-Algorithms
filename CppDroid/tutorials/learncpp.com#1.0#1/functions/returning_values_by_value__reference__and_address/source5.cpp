int* AllocateArray(int nSize)
{
    return new int[nSize];
}

int main()
{
    int *pnArray = AllocateArray(25);
    // do stuff with pnArray

    delete[] pnArray;
    return 0;
}