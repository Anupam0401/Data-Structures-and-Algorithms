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
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int t=a[0],ans=0;
        for(int i=0; i<n; i++){
            if(a[i]>t){
                ans=n-i;
                break;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}