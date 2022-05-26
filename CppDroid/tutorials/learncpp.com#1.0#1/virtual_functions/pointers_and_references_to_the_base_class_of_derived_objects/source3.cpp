int main()
{
    using namespace std;
    Derived cDerived(5);

    // These are both legal!
    Base &rBase = cDerived;
    Base *pBase = &cDerived;

    cout << "cDerived is a " << cDerived.GetName() << " and has value " << cDerived.GetValue() << endl;
    cout << "rBase is a " << rBase.GetName() << " and has value " << rBase.GetValue() << endl;
    cout << "pBase is a " << pBase->GetName() << " and has value " << pBase->GetValue() << endl;

    return 0;
}