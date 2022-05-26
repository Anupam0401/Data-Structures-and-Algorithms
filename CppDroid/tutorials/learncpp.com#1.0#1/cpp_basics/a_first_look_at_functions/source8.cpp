//#include <stdafx.h> // Visual Studio users need to uncomment this line
#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int multiply(int z, int w)
{
    return z * w;
}

int main()
{
    using namespace std;
    cout << add(4, 5) << endl; // evalutes 4 + 5
    cout << add(3, 6) << endl; // evalues 3 + 6
    cout << add(1, 8) << endl; // evalues 1 + 8

    int a = 3;
    int b = 5;
    cout << add(a, b) << endl; // evaluates 3 + 5

    cout << add(1, multiply(2, 3)) << endl; // evalues 1 + (2 * 3)
    cout << add(1, add(2, 3)) << endl; // evalues 1 + (2 + 3)
    return 0;
}