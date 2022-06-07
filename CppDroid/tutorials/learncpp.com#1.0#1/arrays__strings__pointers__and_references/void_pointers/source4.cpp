#include <iostream>

enum Type
{
    INT,
    FLOAT,
    STRING,
};

void Print(void *pValue, Type eType)
{
    using namespace std;
    switch (eType)
    {
        case INT:
            cout << *static_cast<int*>(pValue) << endl;
            break;
        case FLOAT:
            cout << *static_cast<float*>(pValue) << endl;
            break;
        case STRING:
            cout << static_cast<char*>(pValue) << endl;
            break;
    }
}

int main()
{
    int nValue = 5;
    float fValue = 7.5;
    char *szValue = "Mollie";

    Print(&nValue, INT);
    Print(&fValue, FLOAT);
    Print(szValue, STRING);
    return 0;
}