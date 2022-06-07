#include <iostream>

void IncrementAndPrint()
{
    using namespace std;
    static int s_nValue = 1; // fixed duration
    ++s_nValue;
    cout << s_nValue << endl;
} // s_nValue is not destroyed here, but becomes inaccessible

int main()
{
    IncrementAndPrint();
    IncrementAndPrint();
    IncrementAndPrint();
}