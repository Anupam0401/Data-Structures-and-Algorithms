#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#define MOD 1e9+7
using namespace std;
int main()
{
    unsigned int t;
    cin>>t;
    while(t--){
        unsigned int n;
        cin>>n;
        cout<<(int)(pow(2.0,n-1.0))% (float) MOD <<endl;
    }
    return 0;
}