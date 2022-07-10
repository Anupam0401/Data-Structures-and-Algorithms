#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int
using namespace std;

// Polycarp has a poor memory. Each day he can remember no more than 3 of different letters.

// Polycarp wants to write a non-empty string of s consisting of lowercase Latin letters, taking minimum number of days. In how many days will he be able to do it?

// For each test case, print a single number — minimum number of days it will take Polycarp to write the string s from memory.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int ans = 0;
        set<char> st;
        int i = 0;
        // bool flag=0;
        while (i < n)
        {

            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
            }
            i++;
            if (st.size() == 4)
            {
                ans++;
                st.clear();
                i--;
            }
        }
        if (st.size() > 0)
        {
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
