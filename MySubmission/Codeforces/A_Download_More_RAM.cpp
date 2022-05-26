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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector< pair<int,int> > vect;
        for(int i=0;i<n;i++){
            vect.push_back(make_pair(a[i],b[i]));
        }
        sort(vect.begin(),vect.end());
        int ans=0;
        if(vect[0].first>k){
            cout<<k<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            if(vect[i].first>k)   break;
            ans=vect[i].first+vect[i].second+k-vect[i].first;
            k=ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}