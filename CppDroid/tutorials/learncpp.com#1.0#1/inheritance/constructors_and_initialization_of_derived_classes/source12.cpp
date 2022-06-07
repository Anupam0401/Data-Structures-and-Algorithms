#include <iostream>
using namespace std;

class A
{
public:
    A(int nValue)
    {
        cout << "A: " << nValue << endl;
    }
};

class B: public A
{
public:
    B(int nValue, double dValue)
    : A(nValue)
    {
        cout << "B: " << dValue << endl;
    }
};

class C: public B
{
public:
    C(int nValue, double dValue, char chValue)
    : B(nValue, dValue)
    {
        cout << "C: " << chValue << endl;
    }
};

int main()
{
    C cClass(5, 4.3, 'R');

    return 0;
}