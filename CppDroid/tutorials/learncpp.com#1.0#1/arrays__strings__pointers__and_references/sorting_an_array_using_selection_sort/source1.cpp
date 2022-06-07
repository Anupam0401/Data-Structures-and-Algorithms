#include <algorithm> // for swap
#include <iostream>

int main()
{
    using namespace std;

    int x = 2;
    int y = 4;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(x, y); // swap also lives in std namespace
    cout << "After swap:  x = " << x << ", y = " << y << endl;
}