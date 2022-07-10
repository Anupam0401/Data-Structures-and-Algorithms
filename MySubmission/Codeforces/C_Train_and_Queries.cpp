// Along the railroad there are stations indexed from 1 to 109. An express train always travels along a route consisting of n stations with indices u1,u2,…,un, where (1≤ui≤109). The train travels along the route from left to right. It starts at station u1, then stops at station u2, then at u3, and so on. Station un — the terminus.

// It is possible that the train will visit the same station more than once. That is, there may be duplicates among the values u1,u2,…,un.

// You are given k queries, each containing two different integers aj and bj (1≤aj,bj≤109). For each query, determine whether it is possible to travel by train from the station with index aj to the station with index bj.


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
        lli n,k;
        cin>>n>>k;
        vector<lli> a(n);
        map<lli,lli> first_index;
        map<lli,lli> last_index;
        for(lli i=0;i<n;i++)
        {
            cin>>a[i];
            if(first_index.find(a[i])==first_index.end())
            {
                first_index[a[i]]=i;
            }
        }
        vector<lli> b(n);
        // store the reverse of a in b
        for(lli i=0;i<n;i++)
        {
            b[i]=a[n-i-1];
            //last index fill
            if(last_index.find(b[i])==last_index.end())
            {
                last_index[b[i]]=i;
            }
        }
        
        for(lli p=1;p<=k;p++){
            lli aj,bj;
            cin>>aj>>bj;
            // if either aj or bj is not present then, continue
            if(first_index.find(aj)==first_index.end()||last_index.find(bj)==last_index.end())
            {
                cout<<"NO"<<endl;
                continue;
            }
            // find the index at which aj is present
            lli aj_index=first_index[aj];
            // find the index at which bj is present in b
            lli bj_index=last_index[bj];
            bj_index = n-bj_index-1;
            // if aj_index is greater than bj_index then, continue
            // cout<<"\n"<<aj_index<<" "<<bj_index<<endl;
            if(aj_index>bj_index)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else
            {
                cout<<"YES"<<endl;
            }
        }
    }

    return 0;
}
