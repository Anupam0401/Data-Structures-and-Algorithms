#include <cctype>
#include <string>
#include <iostream>
using namespace std;

while (1)
{
    // Get user's name
    cout << "Enter your name: ";
    string strName;
    getline(cin, strName); // get the entire line, including spaces

    bool bRejected=false; // has strName been rejected?

    // Step through each character in the string until we either hit
    // the end of the string, or we rejected a character
    for (unsigned int nIndex=0; nIndex < strName.length() && !bRejected; nIndex++)
    {
        // If the current character is an alpha character, that's fine
        if (isalpha(strName[nIndex]))
            continue;

        // If it's a space, that's fine too
        if (strName[nIndex]==' ')
            continue;

        // Otherwise we're rejecting this input
        bRejected = true;
    }

    // If the input has been accepted, exit the while loop
    // otherwise we're going to loop again
    if (!bRejected)
        break;
}