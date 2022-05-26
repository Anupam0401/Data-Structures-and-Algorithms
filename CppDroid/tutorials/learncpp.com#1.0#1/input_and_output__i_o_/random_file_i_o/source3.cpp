int main()
{
    using namespace std;

    ifstream inf("Sample.dat");

    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }

    string strData;

    inf.seekg(5); // move to 5th character
    // Get the rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;

    inf.seekg(8, ios::cur); // move 8 more bytes into file
    // Get rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;

    inf.seekg(-15, ios::end); // move 15 bytes before end of file
    // Get rest of the line and print it
    getline(inf, strData);
    cout << strData << endl;

	return 0;
}