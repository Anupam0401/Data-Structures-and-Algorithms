#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

int main()
{
    srand(time(0)); // seed random number generator

    string sString; // length 0
    sString.reserve(64); // reserve 64 characters

    // Fill string up with random lower case characters
    for (int nCount=0; nCount < 64; ++nCount)
        sString += 'a' + rand() % 26;

    cout << sString;
}