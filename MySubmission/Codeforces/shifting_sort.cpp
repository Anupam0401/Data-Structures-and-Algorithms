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
const int mod = 2000000007;

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

int diff(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, i, j, k, ans, p;
    cin >> t;
    while (t--)
    {
        ans = 0;
        int flag = 1;
        cin >> n;
        ll a[n], b[n];
        vector<int> l, r, d;
        queue<ll> q, temp;
        fo(i, n)
        {
            cin >> a[i];
            b[i] = a[i];
            q.push(a[i]);
            // if(a[i]<min){
            //     min=a[i];
            //     l=i;
            // }
        }
        temp = q;
        sort(a, a + n);
        // fo(i, n) { cout << a[i] << " "; }
        // cout << endl;
        fo(i, n)
        {
            if (a[i] != temp.front())
            {
                ;
                flag = 0;
                break;
            }
            temp.pop();
        }
        if (flag == 1)
        {
            cout << "0" << endl;
        }
        else
        {
            flag = 0;
            // cout << n - 1 << endl;
            j = 0;
            ans = 0;
            fo(j, n - 1)
            {
                for(i=0; i<n; i++)
                {
                    flag=0;
                    if (b[i] == a[j] && diff(i, j) > 0)
                    {
                        ans++;
                        l.pb(j + 1);
                        r.pb(n);
                        d.pb(diff(j, i));
                        flag = 1;
                        break;
                        // if (i - j > 0)
                        //     cout << j + 1 << " " << n << " " << i - j++ << endl;
                        // else
                        //     cout << j + 1 << " " << n << " " << j++ - i << endl;
                    }
                }
                if (flag)
                {
                    fo(p, d[0])
                    {
                        ll t1 = q.front();
                        q.pop();
                        q.push(t1);
                    }
                    temp = q;
                    fo(p, n)
                    {
                        b[p] = temp.front();
                        temp.pop();
                    }
                }
            }
            // fo(i, n) cout << b[i] << " ";
            // cout << endl;
            cout << ans << endl;
            fo(i, ans)
            {
                cout << l[i] << " " << r[i] << " " << d[i] << endl;
            }
        }
    }
    return 0;
}