#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1000000007;

ll add(ll a, ll b)
{
    a += b;
    return (a >= mod ? a - mod : a);
}

ll sub(ll a, ll b)
{
    a -= b;
    return (a < 0 ? a + mod : a);
}

ll mul(ll a, ll b)
{
    a *= b;
    return (a >= mod ? a % mod : a);
}

ll power(ll a, ll b)
{
    ll result = 1;
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
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll number_of_digits(ll n)
{
    ll k = 0;
    while (n)
    {
        n = n / 10;
        k++;
    }
    return k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    // int a[31] = {1};
    // for (t = 1; t <= 30; t++)
    // {
    //     a[t] = a[t - 1] * 2;
    // }
    cin >> t;
    while (t--)
    {
        ll n, t, d, i, j, k, temp, ans = 0;
        cin >> n >> d;
        temp = n;
        int flag = 0;
        t = number_of_digits(n);

        // cout << t << endl;

        vector<int> v;
        for (i = 1; i <= t; i++)
        {
            v.pb(n % 10);
            if (n % 10 == d)
                flag = 1;
            n = n / 10;
        }
        // for (i = t - 1; i >= 0; i--)
        //     cout << v[i] << " ";
        // cout << endl;
        if (!flag)
            cout << "0" << endl;
        else
        {
            for (i = t - 1; i >= 0; i--)
            {
                if (v[i] == d)
                {
                    if (d == 0)
                    {
                        for (j = i; j >= 0; j--)
                            v[j] = 1;
                    }
                    else if (d == 9)
                    {
                        flag = 0;
                        for (j = i; j >= 0; j--)
                            v[j] = 0;
                        if (i == t - 1){
                            v.pb(1);
                            t++;
                        }
                        else
                        {
                            k = i + 1;
                            while (v[k] + 1 == 9)
                            {
                                v[k] = 0;
                                if (k == t - 1)
                                {
                                    v.pb(1);
                                    t++;
                                    flag = 1;
                                    break;
                                }
                                k++;
                            }
                            if (!flag)
                                v[k] = v[k] + 1;
                        }
                    }
                    else
                    {
                        v[i] = v[i] + 1;
                        for (j = i - 1; j >= 0; j--)
                        {
                            v[j] = 0;
                        }
                    }
                }
            }
            // for (i = t - 1; i >= 0; i--)
            //     cout << v[i] << " ";
            // cout << endl;
            ans = 0;
            for (i = t - 1; i >= 0; i--)
            {
                ans = ans * 10 + v[i];
            }
            cout << ans - temp << endl;
        }
    }
    return 0;
}