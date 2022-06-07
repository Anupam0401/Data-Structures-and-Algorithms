#include <iostream>

int main()
{
    using namespace std;
    // First we'll use the insertion operator on cout to print text to the monitor
    cout << "Enter your age: " << endl;

    // Then we'll use the extraction operator on cin to get input from the user
    int nAge;
    cin >> nAge;

    if (nAge <= 0)
    {
        // In this case we'll use the insertion operatior on cerr to print an error message
        cerr << "Oops, you entered an invalid age!" << endl;
        exit(1);
    }

    // Otherwise we'll use insertion again on cout to print a result
    cout << "You entered " << nAge << " years old" << endl;

    return 0;
}