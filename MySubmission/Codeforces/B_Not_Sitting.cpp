#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;

int optimal(int x,int y,int n,int m){
    int a = abs(x)+abs(y);
    int b = abs(n-1-x)+abs(y);
    int c = abs(x)+abs(m-1-y);
    int d = abs(n-1-x)+abs(m-1-y);
    return max(max(a,b),max(c,d));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> ans;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(optimal(i,j,n,m));
            }
        }
        sort(ans.begin(), ans.end());
        for(auto i:ans){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}