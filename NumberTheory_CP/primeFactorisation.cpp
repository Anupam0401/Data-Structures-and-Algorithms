#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'

void primeFactors(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            int count = 0;
            while(n%i==0){
                count++;
                n = n/i;
            }
            cout<<i<<"^"<<count<<", ";
        }
    }
    cout<<endl;
    return;
}

void primeFactorsII(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count = 0;
            while(n%i==0){
                count++;
                n = n/i;
            }
            cout<<i<<"^"<<count<<",";
        }
    }
    if(n>1) cout<<n<<"^1";
    cout<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    primeFactorsII(n);
    return 0;
}