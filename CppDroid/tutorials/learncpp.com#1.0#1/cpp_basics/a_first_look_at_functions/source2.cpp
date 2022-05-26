//#include <stdafx.h> // Visual Studio users need to uncomment this line
#include <iostream>

// Declaration of function DoPrint()
void DoPrint()
{
    using namespace std;
    cout << "In DoPrint()" << endl;
}

// Declaration of main()
int main()
{
    using namespace std;
    cout << "Starting main()" << endl;
    DoPrint(); // This is a function call to DoPrint()
    DoPrint(); // This is a function call to DoPrint()
    DoPrint(); // This is a function call to DoPrint()
    cout << "Ending main()" << endl;
    return 0;
}