//#include <stdafx.h> // Visual Studio users need to uncomment this line
#include <iostream>

void DoPrint2()
{
    using namespace std;
    cout << "In DoPrint2()" << endl;
}

// Declaration of function DoPrint()
void DoPrint()
{
    using namespace std;
    cout << "Starting DoPrint()" << endl;
    DoPrint2(); // This is a function call to DoPrint2()
    DoPrint2(); // This is a function call to DoPrint2()
    cout << "Ending DoPrint()" << endl;
}

// Declaration of main()
int main()
{
    using namespace std;
    cout << "Starting main()" << endl;
    DoPrint(); // This is a function call to DoPrint()
    cout << "Ending main()" << endl;
    return 0;
}