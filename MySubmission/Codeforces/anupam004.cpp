#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define take vll a(n);for (int i=0;i<n;i++){cin>>a[i];}
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define memory_of_node (struct node *)malloc(sizeof(struct node))
#define vll vector<ll>
#define vpl vector<pair<ll,ll>>
#define mp make_pair
#define s second
#define f first
#define st(v) sort(v.begin(),v.end())
#define Y cout<<"YES"<<endl
#define N cout<<"NO"<<endl
#define SY cout<<"Yes"<<endl
#define SN cout<<"No"<<endl
#define rep(start,upto,increment) for(int j=start;j<upto;j+=increment)
#define sz(a) a.size()
#define mem(a,x) memset(a,x,sizeof(a));
#define mll map<ll,ll>
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define bs binary_search
#define ub upper_bound
ll vmax(vll &v){
   return (*max_element(all(v)));
}
ll vmin(vll &v){
   return (*min_element(all(v)));
}
ll power_mod_m(ll x,ll y,ll p){
   ll res = 1; 
    x = x % p;  
    if (x == 0) return 0; 
    while (y > 0){
        if (y & 1)
            res = ((res%p)*(x%p)) % p;
        y = y>>1;
        x = ((x%p)*(x%p)) % p;
    }
    return res;
}
ll inverse_mod(ll x,ll mod){
   return (power_mod_m(x,mod-2,mod));
}
void solve(){
   
}
int main(){
   fast;
   mt19937 rand(chrono::steady_clock::now().time_since_epoch().count());
   ll t=1;
   cin>>t;
   while (t--){
      solve();
   }
   return 0;
}