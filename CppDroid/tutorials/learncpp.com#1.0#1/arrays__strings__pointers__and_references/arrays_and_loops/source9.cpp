#include <iostream>
int main()
{
    using namespace std;
    int nNumber;
    do
    {
        cout << "Enter a number: ";
        cin >> nNumber;
    } while (nNumber < 1 || nNumber > 9);

    int anArray[9] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    for (int iii=0; iii < 9; iii++)
        cout << anArray[iii] << " ";

    cout << endl;

    for (int jjj=0; jjj< 9; jjj++)
    {
        if (anArray[jjj] == nNumber)
        {
            cout << "The number " << nNumber << " has index " << jjj << endl;
            break; // since each # in the array is unique, no need to search rest of array
        }
    }

    return 0;
}