int main()
{
    Derived cDerived(7);

    // PrintValue is public in Derived, so this is okay
    cDerived.PrintValue(); // prints 7
    return 0;
}