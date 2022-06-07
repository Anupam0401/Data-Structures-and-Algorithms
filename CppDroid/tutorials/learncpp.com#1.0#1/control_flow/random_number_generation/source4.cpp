#include <stdafx.h>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;

int main()
{

    srand(time(0)); // set initial seed value to system clock
    for (int nCount=0; nCount < 100; ++nCount)
    {
        cout << rand() << "\t";

        if ((nCount+1) % 5 == 0)
            cout << endl;
	}
}