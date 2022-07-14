#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
bool f(int x, int y)
{
    return x > y;
}

void vectorDemo()
{
    vector<int> A = {11, 23, 2, 890, 32, 21, 1};
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    //sorting in O(N.logN)
    sort(A.begin(), A.end());

    //searching in O(logN)
    cout << binary_search(A.begin(), A.end(), 23) << endl;

    A.push_back(100);
    A.push_back(23);
    A.push_back(132);

    cout << binary_search(A.begin(), A.end(), 132) << endl;

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);

    //in descending order
    sort(A.begin(), A.end(), f);
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;

    //find the first occurence in O(logN) time
    auto it = lower_bound(A.begin(), A.end(), 100); //>=
    // auto keyword is substitute for vector<int>::iterator
    auto it2 = upper_bound(A.begin(), A.end(), 100); //>
    cout << *it << " " << *it2 << endl;
    cout << it2 - it << endl;
}

void setDemo()
{
    set<int> S;
    S.insert(1);
    S.insert(1221);
    S.insert(231);
    S.insert(21);
    S.insert(1);
    S.insert(17);
    S.insert(21);
    //it does not insert duplicate elements
    //sets inserts elements in ascending order and takes O(logN) time to do so
    //=> it can sort a number of elements in O(logN) time only
    for (int x : S)
    {
        cout << x << " ";
    }
    cout << endl;

    auto it = S.find(231);
    if (it == S.end())
        cout << "Not present\n";
    else
        cout << "Present\n";

    auto it2 = S.upper_bound(17);
    auto it3 = S.lower_bound(17);
    cout << *it2 << " " << *it3 << endl;
}

void mapDemo()
{
    map<int, int> A;
    A[1] = 0;
    A[3] = 12;
    A[12] = 3;
    A[123] = 123;

    map<char, int> count;
    string str = "anupam kumar";
    for (char c : str)
    {
        count[c]++;
    }
    cout << count['a'] << " " << count[' '] << endl;
}

void solve()
{
    set<pair<int, int>> S;
    S.insert({32, 300});
    S.insert({2, 3});
    S.insert({10, 30});
    S.insert({400, 3000});

    int point;
    cout << "Enter a number to find: " << endl;
    cin >> point;
    auto it = S.upper_bound({point, INT_MAX});
    if (it == S.begin())
    {
        cout << "Not present...try again.." << endl;
        return;
    }

    it--;
    pair<int, int> current = *it;
    if (current.first <= point && current.second >= point)
        cout << "present in the range [" << current.first << " , " << current.second << "]\n";
    else
        cout << "Not present....Sorry" << endl;
}

int main()
{
    // vectorDemo();
    setDemo();
    // mapDemo();
    // solve();
    return 0;
}
