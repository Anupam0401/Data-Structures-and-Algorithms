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
void printArray(int a[], int n)
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
bool check(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1)
            return false;
    }
    return true;
}
int find(string s, char c)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
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
        string s;
        cin >> s;
        int n = s.size(), k = 0;
        int a[26] = {0};
        for (int i = 0; i < n; i++)
        {
            a[s[i] - 'a']++;
        }
        //printArray(a,n);
        if (!check(a, n))
        {
            // cout << "hi\n";
            cout << "NO\n";
        }
        else
        {
            int check = 1;
            int ind = find(s, 'a');
            for (int i = ind + 1; i < n; i++)
            {
                if (s[i - 1] >= s[i])
                {
                    check = 0;
                    break;
                }
            }
            for (int i = ind - 1; i >= 0; i--)
            {
                if (s[i] <= s[i + 1])
                {
                    cout << "hi\n";
                    check = 0;
                    break;
                }
            }
            if (check == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}