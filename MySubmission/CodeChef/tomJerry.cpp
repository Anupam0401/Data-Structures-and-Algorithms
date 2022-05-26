#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	long int t;
	cin >> t;
    while(t--) {
        long int a,b,c,d,k,path=0;
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>d;
        cin>>k;
        path+=(c-a)>0?(c-a):(a-c);
        path+=(d-b)>0?(d-b):(b-d);
        if((k-path)%2==0 &&(k-path)>=0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
	return 0;
}