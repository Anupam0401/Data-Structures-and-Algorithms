#include "math.h" // for sqrt() function
using namespace std;

// A modular square root function
double MySqrt(double dX)
{
    // If the user entered a negative number, this is an error condition
    if (dX < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type char*

    return sqrt(dX);
}

int main()
{
    cout << "Enter a number: ";
    double dX;
    cin >> dX;

    // Look ma, no exception handler!
    cout << "The sqrt of " << dX << " is " << MySqrt(dX) << endl;
}