#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,a,b;
        cin>>x>>a>>b;
        int max=a+(100-x)*b;
        cout<<max*10<<endl;
    }
    return 0;
}