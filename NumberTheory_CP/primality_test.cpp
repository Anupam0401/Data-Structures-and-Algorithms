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

int main(){
    int a;
    cin>>a;
    checkPrime(a);
    return 0;
}