#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    using namespace std;

    vector<int> vect;
    vect.push_back(7);
    vect.push_back(-3);
    vect.push_back(6);
    vect.push_back(2);
    vect.push_back(-5);
    vect.push_back(0);
    vect.push_back(4);

    sort(vect.begin(), vect.end()); // sort the list

    vector<int>::const_iterator it; // declare an iterator
    for (it = vect.begin(); it != vect.end(); it++) // for loop with iterators
        cout << *it << " ";

    cout << endl;

    reverse(vect.begin(), vect.end()); // reverse the list

    for (it = vect.begin(); it != vect.end(); it++) // for loop with iterators
        cout << *it << " ";

    cout << endl;
}