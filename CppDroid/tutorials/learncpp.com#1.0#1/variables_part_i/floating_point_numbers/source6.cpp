#include <iostream>
#include <iomanip> // for setprecision()
int main()
{
    using namespace std;

    cout << setprecision(16); // show 16 digits
    float fValue = 3.33333333333333333333333333333333333333f;
    cout << fValue << endl;
    double dValue = 3.3333333333333333333333333333333333333;
    cout << dValue << endl;