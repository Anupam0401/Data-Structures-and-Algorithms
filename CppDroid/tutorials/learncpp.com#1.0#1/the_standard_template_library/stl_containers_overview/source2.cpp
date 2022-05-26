#include <iostream>
#include <deque>
int main()
{
    using namespace std;

    deque<int> deq;
    for (int nCount=0; nCount < 3; nCount++)
    {
        deq.push_back(nCount); // insert at end of array
        deq.push_front(10 - nCount); // insert at front of array
    }

    for (int nIndex=0; nIndex < deq.size(); nIndex++)
        cout << deq[nIndex] << " ";

    cout << endl;
}