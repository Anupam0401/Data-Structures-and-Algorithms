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
        long long int a[2*n],i;
        for(i=0; i<2*n; i++){
            cin>>a[i];
        }
        sort(a,a+2*n);
        
        for(i=0; i<n; i++){
            cout<<a[i]<<" "<<a[i+n]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}