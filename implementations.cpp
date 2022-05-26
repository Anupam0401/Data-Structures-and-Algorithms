#include<bits/stdc++.h>
using namespace std;


void reverse(string s){
    if(s.length() == 0)
        return;
    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}

void replacePI(string s){
    if(s.length() == 0)
        return;
    if(s[0] == 'p' && s[1] == 'i'){
        cout<<"3.14";
        replacePI(s.substr(2));
    }
    else{
        cout<<s[0];
        replacePI(s.substr(1));
    }
}


int main(){
    string s= "anupam";
    reverse(s);
    cout<<endl;
    replacePI("pipicsdiiipippi");
    return 0;
}