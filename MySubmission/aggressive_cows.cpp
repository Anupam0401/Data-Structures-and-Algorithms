#include<bits/stdc++.h>
using namespace std;

#define lli long long int

bool isPossible(vector<lli> &stalls, lli minDist, lli k)
{
    lli cows=1;               // we already place it at the first available slot i.e stalls[0]  ( GREEDY )
    lli lastCowPosition=stalls[0];
    for(lli i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastCowPosition>=minDist)
        {
            cows++;
            lastCowPosition=stalls[i];
            if(cows>=k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<lli> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    lli low=1,high=stalls[n-1]-stalls[0];              // just take low=0 and high = 1000000 any large number if this seems tricky
    lli res;
    while(low<=high)
    {
        lli mid=(low+high)/2;
        if(isPossible(stalls,mid,k))
        {
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<lli> x(n,0);
        for(int i=0;i<n;i++){
            lli temp;
            cin>>temp;
            x[i] = temp;
        }
        cout<<aggressiveCows(x,c)<<endl;
    }
    return 0;
}