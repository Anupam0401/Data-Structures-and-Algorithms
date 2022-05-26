#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;

// There is a grid with n rows and m columns. Some cells are colored black, and the rest of the cells are colored white.

// In one operation, you can select some black cell and do exactly one of the following:

// color all cells in its row black, or
// color all cells in its column black.
// You are given two integers r and c. Find the minimum number of operations required to make the cell in row r and column c black, or determine that it is impossible

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        bool flag = false;
        char v[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                if (v[i][j] == 'B')
                    flag = true;
            }
        }
        if (!flag)
            cout << -1 << endl;
        else
        {
            flag = false;
            int ans = 0;
            if (v[r - 1][c - 1] == 'B')
            {
                ans = 0;
            }
            else
            {
                for (int i = 0; i < m; i++)
                {
                    if (v[r - 1][i] == 'B')
                    {
                        flag = true;
                        ans++;
                        break;
                    }
                }
                for (int i = 0; i < n && !flag; i++)
                {
                    if (v[i][c - 1] == 'B')
                    {
                        flag = true;
                        ans++;
                        break;
                    }
                }
                if (!flag)
                    ans = 2;
            }
            cout << ans << endl;
        }
    }
    return 0;
}