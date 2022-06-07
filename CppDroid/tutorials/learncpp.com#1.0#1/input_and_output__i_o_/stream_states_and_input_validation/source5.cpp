int main()
{
    int nAge;

    while (1)
    {
        cout << "Enter your age: ";
        cin >> nAge;

        if (cin.fail()) // no extraction took place
        {
            cin.clear(); // reset the state bits back to goodbit so we can use ignore()
            cin.ignore(1000, '\n'); // clear out the bad input from the stream
            continue; // try again
        }

        cin.ignore(1000, '\n'); // clear out any additional input from the stream

        if (nAge <= 0) // make sure nAge is positive
            continue;

	break;
    }

    cout << "You entered: " << nAge << endl;
}