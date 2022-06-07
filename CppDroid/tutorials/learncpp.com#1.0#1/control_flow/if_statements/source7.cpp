#include <iostream>
#include <cmath> // for sqrt()

void PrintSqrt(double dValue)
{
    using namespace std;
    if (dValue >= 0.0)
        cout << "The square root of " << dValue << " is " << sqrt(dValue) << endl;
    else
        cout << "Error: " << dValue << " is negative" << endl;
}