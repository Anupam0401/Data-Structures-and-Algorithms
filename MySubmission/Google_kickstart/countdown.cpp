#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    long long int k,n;
    for(int p=1;p<=t;p++){
        cin>>n>>k;
        long long int a[n],temp,count=0;
        temp=k;
        for(long long int i=0;i<n;i++){
            cin>>a[i];
        }
        for(long long int i=0;i<n;i++){
            if(a[i]==temp){
                long long int j=i;
                while(a[j]==temp){
                    if(temp==1) {
                        count++;
                        break;
                    }
                    else{
                        temp--;
                        j++;
                    }
                }
                temp=k;
            }
        }

        cout<<"Case #"<<p<<": "<<count<<endl;

    }
}