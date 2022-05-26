#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nValue;
    cin >> nValue;

    if (nValue > 10 && nValue < 20)
        cout << "Your value is between 10 and 20" << endl;
    else
        cout << "You value is not between 10 and 20" << endl;
    return 0;
}