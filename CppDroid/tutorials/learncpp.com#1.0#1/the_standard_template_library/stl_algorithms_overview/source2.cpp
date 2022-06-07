#include <iostream>
#include <list>
#include <algorithm>
int main()
{
    using namespace std;

    list<int> li;
    for (int nCount=0; nCount < 6; nCount++)
        li.push_back(nCount);

    list<int>::const_iterator it; // declare an iterator
    it = find(li.begin(), li.end(), 3); // find the value 3 in the list
    li.insert(it, 8); // use list::insert to insert the value 8 before it

    for (it = li.begin(); it != li.end(); it++) // for loop with iterators
        cout << *it << " ";

    cout << endl;
}