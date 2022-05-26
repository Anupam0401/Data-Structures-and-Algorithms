// #include "stdafx.h" // Uncomment if Visual Studio user
#include <iostream>

int main()
{
    using namespace std;    // gives us access to cout and endl
    int x;                  // declare an integer variable named x

    // print the value of x to the screen (dangerous, because x is uninitialized)
    cout << x << endl;
}