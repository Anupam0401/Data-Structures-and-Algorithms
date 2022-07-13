// You are given a square grid with n rows and n columns. Each cell contains either 0 or 1.

// In an operation, you can select a cell of the grid and flip it (from 0→1 or 1→0). Find the minimum number of operations you need to obtain a square that remains the same when rotated 0∘, 90∘, 180∘ and 270∘.

#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                char c;
                cin >> c;
                a[j][k] = c - '0';
            }
        }
        int ans = 0;
        for (int j = 0; j < (n + 1) / 2; j++)
        {
            for (int k = 0; k < n / 2; k++)
            {
                int s = a[j][k] + a[k][n - 1 - j] + a[n - 1 - j][n - 1 - k] + a[n - 1 - k][j];
                ans += min(s, 4 - s);
            }
        }
        cout << ans << endl;
    }

    return 0;
}