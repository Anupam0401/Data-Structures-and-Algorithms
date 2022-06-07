#include <iostream>

int main()
{
    using namespace std;
    signed short x = 32767; // largest 2-byte signed value possible
    cout << "x was: " << x << endl;
    x = x + 1; // We desire 32768, but we get overflow!
    cout << "x is now: " << x << endl;
}