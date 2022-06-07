#include <cstdio> // for getchar()
#include <iostream>

using namespace std;

int main()
{
    // count how many spaces the user has entered
    int nSpaceCount = 0;

    // loop 80 times
    for (int nCount=0; nCount < 80; nCount++)
    {
        char chChar = getchar(); // read a char from user

        // exit loop if user hits enter
        if (chChar == '\n')
            break;

        // increment count if user entered a space
        if (chChar == ' ')
            nSpaceCount++;
    }

    cout << "You typed " << nSpaceCount << " spaces" << endl;

    return 0;
}