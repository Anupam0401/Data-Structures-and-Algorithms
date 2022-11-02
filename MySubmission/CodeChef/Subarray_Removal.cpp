#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
using namespace std;

// Chef has a binary array a of length n. In one operation, Chef does the following:

// 1. Select any L and R such that (1≤L<R≤∣A∣)
// 2. Add A[l]⊕A[l+1]⊕⋯⊕A[R] to his score (Here, ⊕ denotes the bitwise XOR operation)
// 3. Remove the subarray A[L...R] from A.

// Determine the maximum score Chef can get after performing the above operation any number of times.

ll maximumScore(vector<ll> &a, int n)
{
    ll score = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        // traverse the array until both 0 and 1 are present
        if (a[i] == 0)
        {
            int x = a[i];
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] != x)
                {
                    score++;
                    i = j - 1;
                    break;
                }
            }
        }
        else{
            int x = a[i];
            bool fl = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] != x)
                {
                    fl=1;
                    score++;
                    i = j - 1;
                    break;
                }
                else if(fl==0 and j-i>=2){
                    score++;
                }
            }
        }
    }
    return score;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << maximumScore(a, n) << endl;
    }
    return 0;
}
