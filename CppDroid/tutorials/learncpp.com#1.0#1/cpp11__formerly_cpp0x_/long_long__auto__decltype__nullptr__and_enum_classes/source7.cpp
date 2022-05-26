#include <iostream>
using namespace std;

int main()
{
    enum Color
    {
        RED,
        BLUE
    };

    enum Fruit
    {
        BANANA,
        APPLE
    };

    Color a = RED;
    Fruit b = BANANA;

    if (a == b) // The compiler will compare a and b as integers
        cout << "a and b are equal" << endl; // and find they are equal!
    else
        cout << "a and b are not equal" << endl;

    return 0;
}