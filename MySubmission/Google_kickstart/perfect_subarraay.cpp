#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, a[mxN], c[2*100*mxN+1];

void solve() {
	cin >> n;
	int s1=0, s2=0;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		if(a[i]<0)
			s1-=a[i];
		else
			s2+=a[i];
	}
	int t=0;
	ll ans=0;
	++c[s1];
	for(int i=0; i<n; ++i) {
		t+=a[i];
		for(int j=0; j*j<=s2; ++j) {
			if(s1+(t-j*j)>=0)
			ans+=c[s1+(t-j*j)];
		}
		++c[s1+t];
	}
	cout << ans << "\n";
	memset(c, 0, 4*(s1+s2+1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}