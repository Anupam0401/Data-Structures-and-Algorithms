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

    // Create a function pointer named pFcn (yes, the syntax is ugly)
    int (*pFcn)(int, int);

    // Set pFcn to point to the function the user chose
    switch (nOperation)
    {
        case 0: pFcn = Add; break;
        case 1: pFcn = Subtract; break;
        case 2: pFcn = Multiply; break;
    }

    // Call the function that pFcn is pointing to with nX and nY as parameters
    cout << "The answer is: " << pFcn(nX, nY) << endl;

    return 0;
}