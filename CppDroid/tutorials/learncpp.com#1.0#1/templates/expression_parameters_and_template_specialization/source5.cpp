int main()
{
    using namespace std;

    // Dynamically allocate a temporary string
    char *strString = new char[40];

    // Ask user for their name
    cout << "Enter your name: ";
    cin >> strString;

    // Store the name
    Storage<char*> strValue(strString);

    // Delete the temporary string
    delete strString;

    // Print out our value
    strValue.Print(); // This will print garbage
}