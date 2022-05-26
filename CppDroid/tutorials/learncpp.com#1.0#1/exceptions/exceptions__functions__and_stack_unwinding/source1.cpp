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

    try // Look for exceptions that occur within try block and route to attached catch block(s)
    {
        cout << "The sqrt of " << dX << " is " << MySqrt(dX) << endl;
    }
    catch (char* strException) // catch exceptions of type char*
    {
        cerr << "Error: " << strException << endl;
    }
}