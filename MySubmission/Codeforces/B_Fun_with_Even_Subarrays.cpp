#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int
using namespace std;

// You are given an array a of n elements. You can apply the following operation to it any number of times:
// Select some subarray from a of even size 2k that begins at position l (1≤l≤l+2⋅k−1≤n, k≥1) and for each i between 0 and k−1 (inclusive), assign the value a[l+k+i] to a[l+i].


// For example, if a=[2,1,3,4,5,3], then choose l=1 and k=2, applying this operation the array will become a=[3,4,3,4,5,3].

// Find the minimum number of operations (possibly zero) needed to make all the elements of the array equal.

void solve(vector<int> a, int n){
    int k = 1;
    int l = 1;
    int count = 0;
    while(k <= n){
        if(l + 2*k - 1 <= n){
            for(int i = 0; i < k; i++){
                if(a[l+k+i] != a[l+i]){
                    count++;
                    a[l+i] = a[l+k+i];
                }
            }
            l += 2*k;
        }
        k++;
    }
    cout << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)  cin>>a[i];
        solve(a,n);
    }

    return 0;
}