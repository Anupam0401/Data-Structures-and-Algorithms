void PrintInt(int nValue)
{
    cout << nValue;
}

int main()
{
    Cents cCents(7);
    PrintInt(cCents.GetCents()); // print 7

    return 0;
}