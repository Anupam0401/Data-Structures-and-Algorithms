#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int n = str.length();
    for(int i=0;i<n;i++){
        int count = 0;
        while(i<n and str[i]=='1'){
            count++;
            i++;
        }
        if(count>=7){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        int count = 0;
        while(i<n and str[i]=='0'){
            count++;
            i++;
        }
        if(count>=7){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}