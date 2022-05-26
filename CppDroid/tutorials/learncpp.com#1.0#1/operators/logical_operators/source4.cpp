#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nValue;
    cin >> nValue;

    if (nValue == 0 || nValue == 1)
        cout << "You picked 0 or 1" << endl;
    else
        cout << "You did not pick 0 or 1" << endl;
    return 0;
}