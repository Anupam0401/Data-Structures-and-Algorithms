#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <set>
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

ll mex(vector<ll> sub, ll prev_mex, ll min)
{
    ll index = sub.size() - 1;
    if (sub.size() == 1)
        return sub[0] > 0 ? 0 : 1;
    else if (min != 0)
        return 0;
    else
    {
        if (sub[index] > prev_mex)
            return prev_mex;
        else
        {
            set<ll> S;
            for (ll i = 0; i < sub.size(); i++)
            {
                S.insert(sub[i]);
            }

            ll i = 0;
            for (ll x : S)
            {
                if (x != i)
                {
                    return i;
                }
                i++;
            }
            return i;
        }
    }
    // return -1;
}

void solve(ll n, ll k, ll v1[])
{
    ll i;
    ll v2[n + 1] = {0}, a1[n + 1] = {0};
    ll mex = 0;
    for (i = 0; i < n; i++)
        if (v1[i] <= n)
            a1[v1[i]]++;

    for (i = 0; i <= n; i++)
    {
        if (a1[i] == 0)
        {
            mex = i;
            break;
        }
    }
    for (ll r = n - 1; r >= 0; r--)
    {
        ll mx = mex;
        ll a2[n + 1] = {0};
        for (i = 0; i <= n; i++)
        {
            a2[i] = a1[i];
        }

        for (ll l = 0; l <= r; l++)
        {
            v2[mx]++;
            if (v1[l] <= r - l)
            {
                a2[v1[l]]--;
                if (v1[l] < mx && a2[v1[l]] == 0)
                    mx = v1[l];
            }
            a2[r - l] = 0;
        }
        if (v1[r] <= r + 1)
        {
            a1[v1[r]]--;
            if (v1[r] < mex && a1[v1[r]] == 0)
            {
                mex = v1[r];
            }
        }
        a1[r] = 0;
    }

    ll Pa = 0;
    fo(i, n + 1)
    {
        Pa += v2[i];
        if (Pa >= k)
        {
            cout << i << endl;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        vector<int> a(3, 0);
        cin>>a[0]>>a[1]>>a[2];
        sort(a.begin(), a.end());
        
        
    }
    return 0;
}
