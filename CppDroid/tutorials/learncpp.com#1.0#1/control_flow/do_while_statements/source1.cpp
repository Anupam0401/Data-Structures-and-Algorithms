#include <iostream>

int main()
{
    using namespace std;

    // nSelection must be declared outside do/while loop
    int nSelection;

    do
    {
        cout << "Please make a selection: " << endl;
        cout << "1) Addition" << endl;
        cout << "2) Subtraction" << endl;
        cout << "3) Multiplication" << endl;
        cout << "4) Division" << endl;
        cin >> nSelection;
    } while (nSelection != 1 && nSelection != 2 &&
            nSelection != 3 && nSelection != 4);

    // do something with nSelection here
    // such as a switch statement

    return 0;
}