#include <iostream>

using namespace std;

// returns true if x and y are equal
bool IsEqual(int x, int y)
{
    return (x == y); // use equality operator to test if equal
}

int main()
{
    cout << "Enter a value: ";
    int x;
    cin >> x;

    cout << "Enter another value: ";
    int y;
    cin >> y;

    bool bEqual = IsEqual(x, y);
    if (bEqual)
        cout << x << " and " << y << " are equal"<<endl;
    else
        cout << x << " and " << y << " are not equal"<<endl;
    return 0;
}