#include <fstream>
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    // ifstream is used for reading files
    // We'll read from a file called Sample.dat
    ifstream inf("Sample.dat");

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        inf >> strInput;
        cout << strInput << endl;
    }

    return 0;

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}