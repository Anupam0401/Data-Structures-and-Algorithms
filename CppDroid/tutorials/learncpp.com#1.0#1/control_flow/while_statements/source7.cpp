#include <iostream>

int main()
{
    using namespace std;

    char chValue = 'a';
    while (chValue <= 'z')
    {
        cout << chValue << " " << static_cast<int>(chValue) << endl;
        chValue++;
    }
}