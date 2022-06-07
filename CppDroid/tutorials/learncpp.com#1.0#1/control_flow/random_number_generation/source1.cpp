#include <stdafx.h>
#include <iostream>
using namespace std;

unsigned int PRNG()
{
    // our initial starting seed is 5323
    static unsigned int nSeed = 5323;

    // Take the current seed and generate a new value from it
    // Due to our use of large constants and overflow, it would be
    // very hard for someone to predict what the next number is
    // going to be from the previous one.
    nSeed = (8253729 * nSeed + 2396403);

    // Take the seed and return a value between 0 and 32767
    return nSeed  % 32767;
}

int main()
{
    // Print 100 random numbers
    for (int nCount=0; nCount < 100; ++nCount)
    {
        cout << PRNG() << "\t";

        // If we've printed 5 numbers, start a new column
        if ((nCount+1) % 5 == 0)
            cout << endl;
	}
}