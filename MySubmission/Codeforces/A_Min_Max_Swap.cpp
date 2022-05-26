#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int
using namespace std;

// You are given two arrays a and b of n positive integers each. 

//You can apply the following operation to them any number of times:
// Select an index i (1≤i≤n) and swap a[i] with b[i] (i. e. ai becomes bi and vice versa).

// Find the minimum possible value of max(a1,a2,…,an)*max(b1,b2,…,bn) you can get after applying such operation any number of times (possibly zero).
void findMin_swap(vector<int> a, vector<int> b,int n){
    for(int i=0;i<n;i++){
        if(a[i]>b[i])   swap(a[i],b[i]);
    }
    int max_a=*max_element(a.begin(),a.end());
    int max_b=*max_element(b.begin(),b.end());
    cout<<max_a*max_b<<endl;
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
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        findMin_swap(a, b ,n);
    }

    return 0;
}