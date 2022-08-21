#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000007
#define lli long long int
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
using namespace std;

lli add(lli a, lli b)
{
    a += b;
    return (a >= mod ? a - mod : a);
}

lli sub(lli a, lli b)
{
    a -= b;
    return (a < 0 ? a + mod : a);
}

lli mul(lli a, lli b)
{
    a *= b;
    return (a >= mod ? a % mod : a);
}

lli power(lli a, lli b)
{
    lli result = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            result = mul(result, a);
        b >>= 1;
        a = mul(a, a);
    }
    return result;
}

lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int diff(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

lli isAP(lli a, int b)
{
    return ((a + b) % 2 == 0) ? (a + b) / 2 : 1000000006;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    // vector<int> store(100006,0);
    // int s=1;
    // for(int i=1;i<=100006;i+=6)
    // {
    //     store[i] = s++;
    //     // if(i<=100)
    //     // cout<<i<<" "<<store[i]<<"; ";
    // }
    for (int p = 1; p <= t; p++)
    {
        int n;
        cin >> n;
        if(n<=5)
        {
            cout<<"Case #"<<p<<": "<<1<<endl;
            continue;
        }
        // vector<int> a(n,0);
        // a[0]=1;
        // int i=5;
        int ans = 0;
        // if(store[n+1]!=0)   ans = store[n+1];
        // else if(store[n]!=0)    ans = store[n];
        // else{
        //     while(n){
        //         if(store[n]!=0)
        //         {
        //             ans = store[n];
        //             break;
        //         }
        //         n--;
        //     }
        // }
        if(n%5==0)  ans = n/5;
        else ans = n/5+1;
        cout << "Case #" << p << ": " << ans << "\n";
    }
    return 0;
}