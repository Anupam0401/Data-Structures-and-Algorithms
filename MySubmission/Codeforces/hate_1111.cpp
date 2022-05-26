#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
    while(t--) {
        long long int n,i;
        cin>>n;
        bool flag=0;
        int a =11,b=111;
        for(i=11;i<=n;i=i*10+1){
            if(n%i==0){
                flag=1;
                break;
            }
        }
        if(flag==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}