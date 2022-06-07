#include <string> // for std::string
#include <iostream>

int main()
{
    using namespace std; // for both cout and string
    cout << "Enter your name: ";
    string strString;
    cin >> strString;
    cout << "Hello, " << strString << "!" << endl;

    cout << "Your name has: " << strString.length() <<
            " characters in it" << endl;
    cout << "The 2nd character is: " << strString[1] << endl;

    strString = "Dave";
    cout << "Your name is now " << strString << endl;
    cout << "Goodbye, " << strString << endl;

    return 0;
}