#include<bits/stdc++.h>
using namespace std;

void checkPrime(int n){
    if(n==1)    cout<<"NOT PRIME"<<endl;
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout<<"NOT PRIME"<<endl;
            return;
        }
    }
    cout<<"PRIME"<<endl;
    return;
}
void checkPrimeII(int n){
    if(n==1)    cout<<"NOT PRIME"<<endl;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<"NOT PRIME"<<endl;
            return;
        }
    }
    cout<<"PRIME"<<endl;
    return;
}

void sievePreCalculate(vector<int> &primes){
    int n = primes.size();
    primes[0] = primes[1]  = 0;
    for(int i=2;i*i<=n;i++){
        if(primes[i]){
            for(int j=i*i;j<=n;j+=i){
                primes[j] = 0;
            }
        }
    }
}
int main(){
    int a;
    cin>>a;
    // checkPrimeII(a);
    vector<int> primes(100001,1);
    sievePreCalculate(primes);
    cout<<primes[a]<<endl;
    return 0;
}