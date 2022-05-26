int main()
{
    double dX;
    if (FromString("3.4", dX))
        cout << dX << endl;
    if (FromString("ABC", dX))
        cout << dX << endl;
}