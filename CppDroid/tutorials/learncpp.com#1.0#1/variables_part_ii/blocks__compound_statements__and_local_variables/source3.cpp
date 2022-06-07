int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nValue;
    cin >> nValue;

    if (nValue > 0)
    {
        if (nValue < 10)
        {
            cout << nValue << " is between 0 and 10" << endl;
        }
    }
}