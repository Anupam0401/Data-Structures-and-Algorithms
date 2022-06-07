#include <iostream>

int main()
{
    using namespace std;
    const int nInterations = 10;

    for (int nValue=1; nValue<nInterations; nValue++)
        cout << nValue << " ";
    cout << endl;

    return 0;
}