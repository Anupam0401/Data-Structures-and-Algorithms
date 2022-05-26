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
        long int n,k;
        cin>>n;
        cin>>k;
        long long int a[n],b[n],i;
        for(i= 0;i<n;i++){
            cin>>a[i];
        }
        long long int sum1=0,sum2=0;
        sort(a,a+n);
        for(i=0;i<n;i++){
            b[i]=a[n-1-i];
        }
        // for(i=0;i<n;i++){
        //     cout<<b[i]<<" ";
        // }
        // cout<<endl;
        for(i=0;i<n && k>0 ; i++){
            if(i%2==0) {
                sum1+=b[i];
                //cout<<"sum1-"<<sum1<<" "<<b[i]<<endl;
            }
            else {
                sum2+=b[i];
                k--;
                //cout<<"sum2-"<<sum2<<" "<<b[i]<<endl;
            }
        }
        if(k<=0) sum2+=b[i];
        //cout<<sum1<<" "<<sum2<<endl;
        if(sum1>sum2){
            cout<<sum1<<endl;
        }
        else cout<<sum2<<endl;
    }
	return 0;
}