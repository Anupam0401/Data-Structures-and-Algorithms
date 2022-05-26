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
ll fdiff(ll a, ll b)
{
    if (a + b > 0)
        return a + b;
    else
        return -(a + b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t, n, i;
    cin >> t;
    while (t--)
    {
        ll odd = 0, ans = 0;
        cin >> n;
        ll a[n], min;
        int flag = 0;
        fo(i, n)
        {
            cin >> a[i];
            if (a[i] & 1)
                odd++;
        }
        min = a[0];
        if (odd)
            cout << "0" << endl;
        else
        {
            ans = a[0];
            fo(i, n - 1)
            {
                ans = gcd(ans, a[i + 1]);
                min = MIN(min, a[i]);
            }
            ans = 0;
            while (min > 1 && flag == 0)
            {
                ans += 2;
                fo(i, n)
                {
                    a[i] = a[i] / 2;
                    if (a[i] & 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                min = min / 2;
            }
            cout << ans / 2 << endl;
        }
    }
    return 0;
}