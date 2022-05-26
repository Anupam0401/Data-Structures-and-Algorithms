int main()
{
    using namespace std;
    Derived cDerived(5);
    cout << "cDerived is a " << cDerived.GetName() << " and has value " << cDerived.GetValue() << endl;

    Derived &rDerived = cDerived;
    cout << "rDerived is a " << rDerived.GetName() << " and has value " << rDerived.GetValue() << endl;

    Derived *pDerived = &cDerived;
    cout << "pDerived is a " << pDerived->GetName() << " and has value " << pDerived->GetValue() << endl;

    return 0;
}