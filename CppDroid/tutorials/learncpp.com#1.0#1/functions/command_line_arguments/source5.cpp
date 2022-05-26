#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "There are " << argc << " arguments:" << endl;

    // Loop through each argument and print its number and value
    for (int nArg=0; nArg < argc; nArg++)
        cout << nArg << " " << argv[nArg] << endl;

    return 0;
}