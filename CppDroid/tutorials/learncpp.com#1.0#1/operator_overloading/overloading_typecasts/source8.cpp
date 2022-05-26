void PrintCents(Cents cCents)
{
    cout << cCents.GetCents();
}

int main()
{
    Dollars cDollars(9);
    PrintCents(cDollars); // cDollars will be cast to a Cents

    return 0;
}