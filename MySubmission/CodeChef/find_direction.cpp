#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000007
#define lli long long int
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin>>x;
        if(x%4==0) cout<<"North"<<endl;
        else if(x%4==1) cout<<"East"<<endl;
        else if(x%4==2) cout<<"South"<<endl;
        else if(x%4==3) cout<<"West"<<endl;
    }
    return 0;
}