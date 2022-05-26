int main(int argc, char *argv[])
{
    using namespace std;
    // If the user didn't provide a filename command line argument,
    // print an error and exit.
    if (argc <= 1)
    {
        cout << "Usage: " << argv[0] << " <Filename>" << endl;
        exit(1);
    }

    char *pFilename = argv[1];

    // open file and process it
}