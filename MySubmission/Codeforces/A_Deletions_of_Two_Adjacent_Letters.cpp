#include <bits/stdc++.h>
#include <algorithm>
#define lli long long int
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        char c;
        cin>>s;
        cin>>c;
        bool flag=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==c&&(i+1)%2==1){
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag)
        cout<<"NO"<<endl;
    }

    return 0;
}