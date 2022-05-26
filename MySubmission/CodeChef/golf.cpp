#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,x,k;
        cin>>n>>x>>k;
        int f=0;
        // for(long long int i=k;i<n+2;i+=k)
        // {
        //     if(i==x){
        //         cout<<"YES"<<endl;
        //         f=1;
        //         break;
        //     }
        //     else if((n+1)-i==x)
        //     {
        //         cout<<"YES"<<endl;
        //         f=1;
        //         break;
        //     }
        // }

        if(x%k==0||(n+1-x)%k==0)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}