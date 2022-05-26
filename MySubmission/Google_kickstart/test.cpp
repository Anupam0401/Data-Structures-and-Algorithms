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

// Problem
// It is important for researchers to write many high quality academic papers. Jorge has recently discovered a way to measure how impactful a researcher's papers are: the H-index.

// The H-index score of a researcher is the largest integer h such that the researcher has h papers with at least h citations each.

// Jorge has written N papers in his lifetime. The i-th paper has Ai citations. The number of citations that each paper has will never change after it is written. Please help Jorge determine his H-index score after each paper he wrote.

// Input
// The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing N, the number of papers Jorge wrote.

// The second line contains N integers. The i-th integer is Ai, the number of citations the i-th paper has.

// Output
// For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is a space-separated list of integers. The i-th integer is the H-index score after Jorge wrote his i-th paper.

void printAns(int t, vector<int> ans){
    cout << "Case #" << t << ": ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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
        int n;
        cin >> n;
        vector<int> citations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> citations[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int c = citations[i];
            int j = i;
            while (j >= 0 && citations[j] >= c)
            {
                ans[j] = i + 1;
                j--;
            }
        }
        printAns(p,ans);
    }
    return 0;
}
