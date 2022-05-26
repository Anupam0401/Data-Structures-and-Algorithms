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
        int n,k,i,d=0;
        cin>>n;
        cin>>k;
        char s[n];
        cin>>s;
        int a[n];
        int q[k];
        for(int p=0;p<k;p++){
            cin>>q[p];
        }
        for(i=0; i<n; i++){
            a[i]=((int)s[i])-48;
        }
        
        // for(i=0; i < n; i++) cout<<a[i]<<" ";
        // cout<<endl;

        for(i=0; i<n-1 && n>1; i++){
            if(a[i]+a[i+1]==1)
                d+=1;
            else
                d+=2;
        }
        // cout<<d<<"\n"<<endl;
        int ans[k]={0};
        if(n>1){
        int x;
        for(i=0;i<k; i++){
            x=q[i]-1;
            if(x==0){
                if(a[x+1]+a[x]==1) ans[i]+=1;
                else ans[i]-=1;
                a[x]=(a[x]==0)?1:0;
            }
            else if(x==n-1){
                if(a[x-1]+a[x]==1) ans[i]+=1;
                else ans[i]-=1;
                a[x]=(a[x]==0)?1:0;
            }
            else{
                if(a[x+1]+a[x]==1) ans[i]+=1;
                else ans[i]-=1;

                if(a[x-1]+a[x]==1) ans[i]+=1;
                else ans[i]-=1;
                a[x]=(a[x]==0)?1:0;
            }
        }
        }
        int sum=d;
        for(i=0;i<k;i++){
            sum+=ans[i];
            cout<<sum<<endl;
        }
    }
	return 0;
}