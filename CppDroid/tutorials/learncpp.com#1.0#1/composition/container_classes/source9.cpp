#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    // Declare an array with 10 elements
    IntArray cArray(10);

    // Fill the array with numbers 1 through 10
    for (int i=0; i<10; i++)
        cArray[i] = i+1;

    // Resize the array to 8 elements
    cArray.Resize(8);

    // Insert the number 20 before the 5th element
    cArray.InsertBefore(20, 5);

    // Remove the 3rd element
    cArray.Remove(3);

    // Add 30 and 40 to the end and beginning
    cArray.InsertAtEnd(30);
    cArray.InsertAtBeginning(40);

    // Print out all the numbers
    for (int j=0; j<cArray.GetLength(); j++)
        cout << cArray[j] << " ";

    return 0;
}