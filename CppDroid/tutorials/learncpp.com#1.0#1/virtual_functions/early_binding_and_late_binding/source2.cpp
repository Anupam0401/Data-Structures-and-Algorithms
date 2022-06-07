#include <iostream>
using namespace std;

int Add(int nX, int nY)
{
    return nX + nY;
}

int Subtract(int nX, int nY)
{
    return nX - nY;
}

int Multiply(int nX, int nY)
{
    return nX * nY;
}

int main()
{
    int nX;
    cout << "Enter a number: ";
    cin >> nX;

    int nY;
    cout << "Enter another number: ";
    cin >> nY;

    int nOperation;
    do
    {
        cout << "Enter an operation (0=add, 1=subtract, 2=multiply): ";
        cin >> nOperation;
    } while (nOperation < 0 || nOperation > 2);

    int nResult = 0;
    switch (nOperation)
    {
        case 0: nResult = Add(nX, nY); break;
        case 1: nResult = Subtract(nX, nY); break;
        case 2: nResult = Multiply(nX, nY); break;
    }

    cout << "The answer is: " << nResult << endl;

    return 0;
}