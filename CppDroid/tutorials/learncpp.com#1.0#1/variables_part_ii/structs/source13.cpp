#include <iostream>

struct Fraction
{
    int nNumerator;
    int nDenominator;
};

void Multiply(Fraction sF1, Fraction sF2)
{
    using namespace std;

    // Don't forget the static cast, otherwise the compiler will do integer division!
    cout << static_cast<float>(sF1.nNumerator * sF2.nNumerator) /
        (sF1.nDenominator * sF2.nDenominator);
}

int main()
{
    using namespace std;

    // Allocate our first fraction
    Fraction sF1;
    cout << "Input the first numerator: ";
    cin >> sF1.nNumerator;
    cout << "Input the first denominator: ";
    cin >> sF1.nDenominator;

    // Allocate our second fraction
    Fraction sF2;
    cout << "Input the second numerator: ";
    cin >> sF2.nNumerator;
    cout << "Input the second denominator: ";
    cin >> sF2.nDenominator;

    Multiply(sF1, sF2);

    return 0;
}