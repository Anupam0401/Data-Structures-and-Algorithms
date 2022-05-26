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

void printOneSubset(int n, int sum)
{
    int i, j;
    vector<int> temp;
    for(int i =n; i>=1; i--)
    {
        if(i<=sum)
        {
            temp.push_back(i);
            sum-=i;
        }
    }
    cout<<temp.size()<<" "<<endl;
    // print temp
    for(int j=0; j<temp.size(); j++)
    {
        cout<<temp[j]<<" ";
    }
    cout << endl;
}

//Alan chooses a non empty subset of length N and Barabara chooses the rest of the numbers from 1 to N. which Alan has not chosen.
// Alan believes in a magic ratio, which is X:Y. Hence, Alan wants to choose the subset in such a way that the ratio between the sum of Alan's subset and the sum of Barbara's subset is exactly X:Y.
// gcd(X,Y) = 1
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        // done_once = false;
        lli n,x,y;
        cin >> n >> x >> y;
        lli total_sum = n*(n+1)/2;
        lli alan_sum = 0;
        lli barbara_sum = 0;
        bool possible=false;
        if((total_sum*y) % (x+y)==0)   possible=true;
        if(!possible)
        {
            cout << "Case #" << p << ": " << "IMPOSSIBLE" << "\n";
            continue;
        }
        barbara_sum = (total_sum*y) / (x+y);
        alan_sum = total_sum - barbara_sum;
        // int arr[n];
        // for(int i=0;i<n;i++)
        // {
        //     arr[i] = i+1;
        // }
        cout << "Case #" << p << ": " << "POSSIBLE" << "\n";
        printOneSubset(n,alan_sum);
    }
    return 0;
}