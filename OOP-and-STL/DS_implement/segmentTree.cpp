# include <bits/stdc++.h> 
using namespace std ; 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int inf = 1e9 ; 

class SegmentTree
{
	int size ; 
	vector<int> seg ;

	public : 
	SegmentTree(int n) 
	{
		seg.assign(4*n,0) ; 
	}

	int fn(int x, int y) {
		return x + y;
	}
	

	void build(int v, int l, int r, vector<int> &a)
	{
		if(l == r) {
			seg[v] = a[l] ; 
			return ; 
		}
		if(l > r) 
			return ;
		int m = (l + r) / 2 ; 
		build(v*2, l , m , a) ; 
		build(v*2 + 1, m+1, r, a) ;
		seg[v] = fn( seg[v*2] , seg[v*2+1] ) ; 

	}

	void update(int v, int l , int r, int idx, int value) 
	{
		if(l == r) {
			seg[v] = value ;
			return ; 
		}
		int m = (l + r) / 2 ; 
		if(idx <= m) {
			update(v * 2, l , m , idx, value) ;
		} else {
			update(v * 2 + 1, m + 1, r , idx , value) ;
		}
		seg[v] = fn( seg[v*2] , seg[v*2+1] ) ; 
		
	}

	int sum(int v, int l, int r, int ql, int qr) 
	{
		if(l > qr || r < ql )
			return 0 ; 
		if(l >= ql && qr >= r)
			return seg[v] ; 
		int m = (l + r) / 2 ; 
		int lval = sum(v*2, l, m, ql, qr) ; 
		int rval = sum(v*2 + 1, m + 1, r, ql, qr) ; 
		return fn(lval, rval);
	}

	
};


int32_t main() {
	IOS ; 

	return 0 ; 
	
}