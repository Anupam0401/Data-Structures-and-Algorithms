#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nX;
    cin >> nX;

    if (nX > 10)
        // it is bad coding style to nest if statements this way
        if (nX < 20)
            cout << nX << "is between 10 and 20" << endl;

        // who does this else belong to?
        else
            cout << nX << "is greater than 20" << endl;

    return 0;
}