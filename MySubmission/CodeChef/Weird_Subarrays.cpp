#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
using namespace std;

// An array A is called weird if it can be sorted in non-decreasing order by applying the given operation any number of times:

// Select any index i(1≤i≤∣A∣) and set A[i] := -A[i]

// For example: A = [2, 1, 3]A=[2,1,3] is weird since after applying the operation at i = 1i=1, A becomes [-2, 1, 3][−2,1,3] which is sorted.

// J has a permutation P of length N. He wants to find the number of subarrays of P which are weird. Can you help him?
ll countWeirdSubarrays(vector<ll> &a, int n){
    ll c = 0;
    c+= n-1 + n;
    vector<ll> diff(n-1);
    for(int i=0; i<n-1; i++){
        diff[i] = a[i+1] - a[i];
    }
    for(int i=0; i<n-1; i++){
        if(diff[i] < 0){
            c++;
        }
    }
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
        cin>>n;
        vector<ll> nums(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<countWeirdSubarrays(a,n)<<endl;
    }
    return 0;
}