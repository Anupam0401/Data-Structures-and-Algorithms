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

typedef struct Attraction
{
    int start, end, happiness;
} Attraction;

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
vector<Attraction> festival;
Attraction temp;
int d, n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        ll n, d, c, m, i, j, ans = 0;
        cin >> n >> d >> c >> m;
        string s;
        cin >> s;
        ll dog = -1, cat = 0;
        fo(i, n)
        {
            if (s[i] == 'D')
                dog = i;
            else
                cat++;
        }
        ans = 1;
        // cout<<dog<<" "<<cat<<endl;
        for (i = 0; i <= dog; i++)
        {
            if (d <= 0 || (cat > 0 && c <= 0 && s[i]=='C'))
            {
                ans = 0;
                break;
            }
            if (s[i] == 'D')
            {
                d--;
                c += m;
            }
            else
            {
                c--;
                cat--;
            }
        }
        if(ans)
        cout << "Case #" << p << ": " << "YES" << "\n";
        else
        cout << "Case #" << p << ": " << "NO" << "\n";
    }
    return 0;
}