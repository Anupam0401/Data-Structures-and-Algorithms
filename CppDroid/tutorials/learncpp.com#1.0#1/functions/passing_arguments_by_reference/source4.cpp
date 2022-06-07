#include <iostream>
#include <math.h>    // for sin() and cos()

void GetSinCos(double dX, double &dSin, double &dCos)
{
    dSin = sin(dX);
    dCos = cos(dX);
}

int main()
{
    double dSin = 0.0;
    double dCos = 0.0;

    // GetSinCos will return the sin and cos in dSin and dCos
    GetSinCos(30.0, dSin, dCos);

    std::cout << "The sin is " << dSin << std::endl;
    std::cout << "The cos is " << dCos << std::endl;
    return 0;
}