#include <iostream>

int main()
{
    using namespace std;
    cout << "Enter a number: ";
    int nValue;
    cin >> nValue;

    if (nValue > 0)
    { // start of nested block
        cout << nValue << " is a positive number" << endl;
        cout << "Double this number is " << nValue * 2 << endl;
    } // end of nested block
}