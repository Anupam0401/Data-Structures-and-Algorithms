#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nX;
    cin >> nX;

    if (nX > 10)
        {
        // both statements will be executed if nX > 10
        cout << "You entered " << nX << endl;
        cout << nX << "is greater than 10" << endl;
        }
    else
        {
        // both statements will be executed if nX <= 10
        cout << "You entered " << nX << endl;
        cout << nX << "is not greater than 10" << endl;
        }

    return 0;
}