#include <iostream>

int main()
{
    using namespace std;
    unsigned short x = 65535; // largest 2-byte unsigned value possible
    cout << "x was: " << x << endl;
    x = x + 1; // We desire 65536, but we get overflow!
    cout << "x is now: " << x << endl;
}