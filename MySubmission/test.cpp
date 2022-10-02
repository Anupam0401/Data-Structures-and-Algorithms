
#include<bits/stdc++.h>
#define ll long long
using namespace std;


void sievePreCalculate(vector<bool> &primes){
    int n = primes.size();
    primes[0] = primes[1]  = 1;
    for(int i=2;i*i<=n;i++){
        if(!primes[i]){
            for(int j=i*i;j<=n;j+=i){
                primes[j] = 1;
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    vector<bool> primes(90000001,false);
    sievePreCalculate(primes);
    vector<ll> res;
    for(int i=2;i<=90000000;i++)	if(!primes[i])	res.push_back(i);
    while(t--){
    	ll n;
    	cin>>n;
    	cout<<res[n-1]<<endl;
    }
    return 0;
}