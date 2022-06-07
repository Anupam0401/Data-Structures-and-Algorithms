#include <iostream>

void PrintInformation(Employee sEmployee)
{
    using namespace std;
    cout << "ID:   " << sEmployee.nID << endl;
    cout << "Age:  " << sEmployee.nAge << endl;
    cout << "Wage: " << sEmployee.fWage << endl << endl;
}

int main()
{
    Employee sJoe; // create an Employee struct for Joe
    sJoe.nID = 14;
    sJoe.nAge = 32;
    sJoe.fWage = 24.15;

    Employee sFrank; // create an Employee struct for Frank
    sFrank.nID = 15;
    sFrank.nAge = 28;
    sFrank.fWage = 18.27;

    // Print Joe's information
    PrintInformation(sJoe);

    // Print Frank's information
    PrintInformation(sFrank);

    return 0;
}