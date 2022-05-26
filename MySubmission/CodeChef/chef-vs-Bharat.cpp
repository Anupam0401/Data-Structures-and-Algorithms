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

lli chefora(lli n)
{
    lli temp = n / 10;
    while (temp)
    {
        n = n * 10 + (temp % 10);
        temp = temp / 10;
    }
    // cout << n << endl;
    return n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli chef_num[100001] = {0}, chef_sum[100001] = {0};
    for (lli p = 1; p < 100001; p++)
    {
        chef_num[p] = chefora(p);
        chef_sum[p] = chef_sum[p - 1] + chef_num[p];
    }
    // for (lli i = 0; i < 100; i++)
    // {
    //     cout << chef_num[i] << " " << chef_sum[i] << endl;
    // }
    int t;
    cin >> t;
    while (t--)
    {
        lli l, r, i, sum = 0, ans;
        cin >> l >> r;
        if (l + 1 == r)
            sum = chef_num[l + 1];
        else
        {
            sum = chef_sum[r] - chef_sum[l];
        }
        ans = power(chef_num[l], sum);
        cout << ans % mod << endl;
    }
    return 0;
}