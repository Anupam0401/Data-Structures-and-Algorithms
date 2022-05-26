int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nX;
    cin >> nX;

    if (nX > 10)
        cout << nX << "is greater than 10" << endl;
    else if (nX < 5)
        cout << nX << "is less than 5" << endl;
    // could add more else if statements here
    else
        cout << nX << "is between 5 and 10" << endl;

    return 0;
}