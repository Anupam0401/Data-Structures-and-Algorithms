// You are given a square grid with n rows and n columns. Each cell contains either 0 or 1.

// In an operation, you can select a cell of the grid and flip it (from 0→1 or 1→0). Find the minimum number of operations you need to obtain a square that remains the same when rotated 0∘, 90∘, 180∘ and 270∘.

#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int
using namespace std;

int makeSymmetric(vector<vector<char>>& grid, int n)
{
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n && i!=j;j++){
            if(grid[i][j]!=grid[j][i]){
                ans++;
                grid[i][j]=grid[j][i];
            }
        }
    }
    return ans;
}
int makeRowsPalindomre(vector<vector<char>>& grid, int n)
{
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            if(grid[i][j]!=grid[i][n-j-1]){
                ans++;
                grid[i][j]=grid[i][n-j-1];
            }
        }
    }
    return ans;
}
int makeColsPalindomre(vector<vector<char>>& grid, int n)
{
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            if(grid[j][i]!=grid[n-j-1][i]){
                ans++;
                grid[j][i]=grid[n-j-1][i];
            }
        }
    }
    return ans;
}
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
        vector<vector<char>> grid(n,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> grid[i][j];
            }
        }
        vector<vector<char>> temp;
        temp.resize(n,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=grid[j][i];
            }
        }
        int ans;
        // call the 3 function in all orders and determine the minimum ans
        ans = makeRowsPalindomre(grid,n) + makeColsPalindomre(grid,n) + makeSymmetric(grid,n);
        cout<<ans<<endl;

    }

    return 0;
}