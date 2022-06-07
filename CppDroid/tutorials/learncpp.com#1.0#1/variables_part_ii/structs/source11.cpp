struct Employee
{
    int nID;
    int nAge;
    float fWage;
};

struct Company
{
    Employee sCEO; // Employee is a struct within the Company struct
    int nNumberOfEmployees;
};

Company sCo1 = {{1, 42, 60000.0f}, 5};