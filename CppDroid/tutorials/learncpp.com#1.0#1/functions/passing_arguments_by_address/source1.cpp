void foo(int *pValue)
{
    *pValue = 6;
}

int main()
{
    int nValue = 5;

    cout << "nValue = " << nValue << endl;
    foo(&nValue);
    cout << "nValue = " << nValue << endl;
    return 0;
}