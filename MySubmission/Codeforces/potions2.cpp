#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
 
	long long int n;
    cin>>n;
    long long int a[n],i,sum=0,max=0;
    for(i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum>=0) {
        max=n;
        cout<<max<<endl;
        return 0;
    }
 
    sort(a,a+n);
    max=0;
    sum=0;
    for(i=n-1; i>=0; i--)
    {
        sum+=a[i];
        if(sum<0){
            break;
        }
        max++;
    }
    cout<<max<<endl;
	return 0;
}