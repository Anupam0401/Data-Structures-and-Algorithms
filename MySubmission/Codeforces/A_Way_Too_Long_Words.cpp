#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        int x = s.length();
        if(x<=10)   cout<<s<<endl;
        else{
            cout<<s[0]<<x-2<<s[x-1]<<endl;
        }
    }
    return 0;
}