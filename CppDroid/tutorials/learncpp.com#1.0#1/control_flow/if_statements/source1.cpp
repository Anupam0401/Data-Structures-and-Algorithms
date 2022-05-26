#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nX;
    cin >> nX;

    if (nX > 10)
        cout << nX << "is greater than 10" << endl;
    else
        cout << nX << "is not greater than 10" << endl;

    return 0;
}