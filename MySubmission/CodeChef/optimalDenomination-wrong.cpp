#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000000000007
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, fm = 0, fs = 0, fM = 0;
        cin >> n;
        lli a[n], i, min = 1000000001, sec_min = 1000000001, max = 0, ans = 0, sum = 0;
        bool flag = false;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (a[i] > max)
                max = a[i];
            if (a[i] < min)
            {
                sec_min = min;
                min = a[i];
            }
            else if (a[i] < sec_min && a[i] != min)
                sec_min = a[i];
        }
        for (i = 0; i < n; i++)
        {
            if (a[i] == min)
                fm++;
            if (a[i] == sec_min)
                fs++;
            if (a[i] == max)
                fM++;
        }
        // cout << min << ":" << fm << " " << sec_min << ":" << fs << " " << max << ":" << fM << endl;
        if (n == 1 || n == 2)
        {
            ans = n;
        }
        else
        {
            if (fm > 1)
            {
                for (i = 0; i < n; i++)
                {
                    ans += a[i] / min;
                    if (a[i] % min != 0)
                        flag = true;
                }
                ans = ans - (max / min) + 1;
            }
            else
            {
                if (fM == 1)
                {
                    lli temp = 0;
                    bool flag_min = false, flag_sec = false;
                    for (i = 0; i < n; i++)
                    {
                        temp += a[i] / min;
                        if (a[i] % min != 0 && a[i] != max)
                            flag_min = true;

                        ans += a[i] / sec_min;
                        if (a[i] > sec_min && a[i] % sec_min != 0)
                            flag_sec = true;
                    }
                    ans += 1;
                    temp = temp - (max / min) + 1;
                    if (temp < ans && !flag_min)
                        ans = temp;
                    else if (flag_sec && !flag_min)
                        ans = temp;
                    else if (flag_sec)
                        flag = true;
                }
                else
                {
                    for (i = 0; i < n; i++)
                    {
                        ans += a[i] / sec_min;
                        if (a[i] % sec_min != 0 && a[i] != min)
                            flag = true;
                    }
                    ans += 1;
                }
            }
        }
        if (flag)
            cout << sum - max + 1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}