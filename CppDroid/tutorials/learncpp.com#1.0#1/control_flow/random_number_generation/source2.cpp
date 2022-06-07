#include <stdafx.h>
#include <iostream>
#include <cstdlib> // for rand() and srand()
using namespace std;

int main()
{
    srand(5323); // set initial seed value to 5323

    // Print 100 random numbers
    for (int nCount=0; nCount < 100; ++nCount)
    {
        cout << rand() << "\t";

        // If we've printed 5 numbers, start a new column
        if ((nCount+1) % 5 == 0)
            cout << endl;
	}
}