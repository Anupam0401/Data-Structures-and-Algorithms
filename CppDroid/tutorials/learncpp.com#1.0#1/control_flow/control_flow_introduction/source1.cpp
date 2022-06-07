#include <cstdlib>
#include <iostream>

int main()
{
    using namespace std;
    cout << 1;
    exit(0); // terminate and return 0 to operating system

    // The following statements never execute
    cout << 2;
    return 0;
}