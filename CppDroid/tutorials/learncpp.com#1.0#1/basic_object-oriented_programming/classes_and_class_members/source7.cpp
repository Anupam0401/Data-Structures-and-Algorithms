#include <iostream>
class Employee
{
public:
    char m_strName[25];
    int m_nID;
    double m_dWage;

    // Set the employee information
    void SetInfo(char *strName, int nID, double dWage)
    {
        strncpy(m_strName, strName, 25);
        m_nID = nID;
        m_dWage = dWage;
    }

    // Print employee information to the screen
    void Print()
    {
        using namespace std;
        cout << "Name: " << m_strName << "  Id: " <<
            m_nID << "  Wage: $" << m_dWage << endl;
    }
};

int main()
{
    // Declare two employees
    Employee cAlex;
    cAlex.SetInfo("Alex", 1, 25.00);

    Employee cJoe;
    cJoe.SetInfo("Joe", 2, 22.25);

    // Print out the employee information
    cAlex.Print();
    cJoe.Print();

    return 0;
}