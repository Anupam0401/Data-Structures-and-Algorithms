#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nX;
    cin >> nX;

    if (nX > 10)
    {
        if (nX < 20)
            cout << nX << "is between 10 and 20" << endl;
        else // attached to inner if statement
            cout << nX << "is greater than 20" << endl;
    }

    return 0;
}