#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define lli long long int
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        lli a1,a2;
        lli sum=0;
        for(int i=1;i<=3;i++){
            cin>>a1>>a2;
            sum=max(sum,a1+a2);
        }
        cout<<sum<<endl;
    }
    return 0;
}