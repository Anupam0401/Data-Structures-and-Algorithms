#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int GetUserInput()
{
    cout << "Please enter an integer: ";
    int nValue;
    cin >> nValue;
    return nValue;
}

char GetMathematicalOperation()
{
    cout << "Please enter an operator (+,-,*,or /): ";

    char chOperation;
    cin >> chOperation;
    // What if the user enters an invalid character?
    // We'll ignore this possibility for now
    return chOperation;
}

int CalculateResult(int nX, char chOperation, int nY)
{
    if (chOperation=='+')
        return nX + nY;
    if (chOperation=='-')
        return nX - nY;
    if (chOperation=='*')
        return nX * nY;
    if (chOperation=='/')
        return nX / nY;

    return 0;
}

void PrintResult(int nResult)
{
    cout << "Your result is: " << nResult << endl;
}

int main()
{
    // Get first number from user
    int nInput1 = GetUserInput();

    // Get mathematical operation from user
    char chOperator = GetMathematicalOperation();

    // Get second number from user
    int nInput2 = GetUserInput();

    // Calculate result
    int nResult = CalculateResult(nInput1, chOperator, nInput2);

    // Print result
    PrintResult(nResult);
}