#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	long int t;
	cin >> t;
    int f=0;
    while(t--) {
        long long int n;
        cin>>n;
        long long int a[n],min;
        for(long long int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        long long int t,ans=0;
        if(a[0]>=0){
            ans=0;
            if(a[0]==0){
                ans++;
                for(long long int i=1;i<n;i++){
                    if(a[i]==0){
                        ans++;
                        f=1;
                    }
                    if(a[i]>0&&f==0){
                        ans++;
                        t=a[i];
                        for(long long int j=0;j<n;j++){
                            if(a[j]==t) ans++;
                            else break;
                        }
                        break;
                    }
                }
            }
            else{
                ans=1;
            }
        }
        else{
            ans=0;
            min=(a[0]-a[1]<=0)?a[1]-a[0]:a[0]-a[1];
            long long int diff,index=0;
            if(a[0]<0 && a[n-1]<=0){
                ans=n;
            }  
            else if(a[0]<0&&a[n-1]>0){
                ans=0;
                for(long long int i=1;i<n && a[i]<0 ;i++){
                    diff=(a[i]-a[i+1]<=0)?a[i+1]-a[i]:a[i]-a[i+1];
                    if(diff<min) min=diff;
                    index=i;
                }
                ans=index+1;
                f=0;
                for(long long int i=index+1;i<n;i++){
                    if(a[i]==0){ 
                        ans++;
                        if(a[i+1]==0) f=1;
                        }
                    else if(a[i]<=min && f==0){
                        ans++;
                        break;
                    }
                    else break;
                }

            }
        }
        cout<<ans<<endl;
    }
	return 0;
}