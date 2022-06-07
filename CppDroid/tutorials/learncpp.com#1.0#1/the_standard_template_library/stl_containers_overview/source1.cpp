#include <vector>
#include <iostream>
int main()
{
    using namespace std;

    vector<int> vect;
    for (int nCount=0; nCount < 6; nCount++)
        vect.push_back(10 - nCount); // insert at end of array

    for (int nIndex=0; nIndex < vect.size(); nIndex++)
        cout << vect[nIndex] << " ";

    cout << endl;
}