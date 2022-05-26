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
        long long int n,i,k=0;
        cin>>n;
        int a[n];
        for(i=0; i<n; i++){
            cin>>a[i];
        }
        k=(n/2)*6;
        cout<<k<<endl;
        for(i=0; i<n-1; i+=2){
            cout<<"1 "<<i+1<<" "<<i+2<<endl;
            cout<<"2 "<<i+1<<" "<<i+2<<endl;
            cout<<"1 "<<i+1<<" "<<i+2<<endl;
            cout<<"1 "<<i+1<<" "<<i+2<<endl;
            cout<<"2 "<<i+1<<" "<<i+2<<endl;
            cout<<"1 "<<i+1<<" "<<i+2<<endl;
        }
        
    }
	return 0;
}