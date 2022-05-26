#include <iostream>

void IncrementAndPrint()
{
    using namespace std;
    int nValue = 1; // automatic duration by default
    ++nValue;
    cout << nValue << endl;
} // nValue is destroyed here

int main()
{
    IncrementAndPrint();
    IncrementAndPrint();
    IncrementAndPrint();
}