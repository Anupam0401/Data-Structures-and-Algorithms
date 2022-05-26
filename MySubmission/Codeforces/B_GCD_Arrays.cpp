#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli l,r,k;
        cin>>l>>r>>k;
        if(l==r&&l>1)  cout<<"YES"<<endl;
        else if(l==r&&l==1) cout<<"NO"<<endl;
        else{
            if(l&1 && r&1){
                if(((r-l+1)/2+1) <=k)
                cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if((r-l+1)/2  <= k)    cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}