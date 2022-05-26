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
    for (int p = 1; p <= t; p++)
    {
        int min[4]={0};
        cout << "Case #" << p << ": ";
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        min[0]=a,min[1]=b,min[2]=c,min[3]=d;
        for(int i=1;i<=2;i++){
            cin>>a>>b>>c>>d;
            if(a<min[0]) min[0]=a;
            if(b<min[1]) min[1]=b;
            if(c<min[2]) min[2]=c;
            if(d<min[3]) min[3]=d;
        }
        if(min[0]+min[2]+min[3]+min[1]<1000000) cout<<"IMPOSSIBLE"<<endl;
        else{
            int i=0;
            int limit=1000000;
            int on_going = 0;
            while(i<4){
                if(on_going+min[i]<=limit){
                    cout<<min[i]<<" ";
                    on_going+=min[i];
                }
                else{
                    if(limit-on_going>0){
                        cout<<limit-on_going<<" ";
                        on_going+=limit-on_going;
                    }
                    else cout<<"0 ";
                }
                i++;
            }
            cout<<endl;
        }
    
    }
    return 0;
}