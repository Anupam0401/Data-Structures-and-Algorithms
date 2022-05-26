#include <bits/stdc++.h>
using namespace std;

unsigned long long int g,k,sum=0,temp;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
    int t;
    cin>>t;
    unsigned long long int n, ans, i , j;
    for(int p=1;p<=t;p++){
        ans=0;
        cin>>n;
        for(i=1;i<=n;i++){
        sum=0;
        for(j=i;sum<=n;j++){
            if(sum==n) {
                cout<<i<<"\n";
                ans++;
            }
            sum+=j;
        }
        }
        cout<<"Case #" <<p<<": "<<ans<<endl;
    }
    return 0;
}