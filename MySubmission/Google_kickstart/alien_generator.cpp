#include <bits/stdc++.h>
using namespace std;

long long int g,k,sum=0,temp,i;
//int x;

void solve() {
	cin>>g;
    for(i=g-1;i>=1;i--){
        sum=i;
        temp=i;
        while(sum<=g){
            if(sum==g){
                k++;
                //cout<<i<<"\n";
                i=((g/(g/i))<i)?g/(g/i):g/((g/i)+1)+1;
                break;
            }
            sum+=++temp;
        }
    }

	cout << k << "\n";
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int t;
	cin >> t;
	for(int p=1; p<=t; ++p) {
		cout << "Case #" << p << ": ";
        k=1;
        //x=1;
		solve();
	}
}