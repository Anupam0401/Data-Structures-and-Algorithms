#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef priority_queue<int> mx_heap;
typedef priority_queue<int, vector<int>, greater<int>> mn_heap;
typedef unordered_map<int, int> mp;
typedef vector<int> vint;
typedef vector<string> vstr;
#define pb push_back
#define mod 1000000007
void dfs(vector<ll> adj[], int i, int visited[])
{
    if (visited[i] == 0)
    {
        visited[i] = 1;
        for (int j = 0; j < adj[i].size(); j++)
        {
            dfs(adj, adj[i][j], visited);
        }
    }
}
void printArray(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int max_length(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(sum, a[i]);
    }
    return sum;
}
ll sum(int a[], int n)
{
    ll result = 0;
    for (int i = 0; i < n; i++)
    {
        result += a[i];
    }
    return result;
}

vector<int> perfix_function(string s)
{
    int n = s.size();
    vector<int> pattern(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = pattern[i - 1];
        while (j > 0 and s[j] != s[i])
        {
            j = pattern[j - 1];
        }
        if (s[j] == s[i])
            j++;
        pattern[i] = j;
    }
    return pattern;
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;

    t = 1;
    cin >> t;
    while (t--)
    {
        int k, n, m;
        cin >> k >> n >> m;
        int monocarp[n], polycarp[m];
        for (int i = 0; i < n; i++)
            cin >> monocarp[i];
        for (int i = 0; i < m; i++)
            cin >> polycarp[i];
        vector<int> vec;
        int count = n + m, i = 0, j = 0, check = 1;
        while (count)
        {
            if (i < n and monocarp[i] == 0)
            {
                k++;
                i++;
                vec.pb(monocarp[i - 1]);
            }
            else if (j < m and polycarp[j] == 0)
            {
                k++;
                j++;
                vec.pb(polycarp[j - 1]);
            }
            else if (i < n and monocarp[i] != 0 and k >= monocarp[i])
            {
                i++;
                vec.pb(monocarp[i - 1]);
            }
            else if (j < m and polycarp[j] != 0 and k >= polycarp[j])
            {
                j++;
                vec.pb(polycarp[j - 1]);
            }
            else
            {
                check = 0;
                break;
            }
            count--;
            //printArray(vec,vec.size());
        }
        if (check == 0)
        {
            cout << "-1\n";
        }
        else
            printArray(vec, n + m);
    }

    return 0;
}