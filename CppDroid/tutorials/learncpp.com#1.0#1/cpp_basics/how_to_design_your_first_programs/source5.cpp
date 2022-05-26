char GetMathematicalOperation()
{
    cout << "Please enter an operator (+,-,*,or /): ";

    char chOperation;
    cin >> chOperation;

    // What if the user enters an invalid character?
    // We'll ignore this possibility for now
    return chOperation;
}