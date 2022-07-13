// You are given n strings s1,s2,…,sn of length at most 8.

// For each string si, determine if there exist two strings sj and sk such that si=sj+sk. That is, si is the concatenation of sj and sk. Note that j can be equal to k.

// Recall that the concatenation of strings s and t is s+t=s1s2…spt1t2…tq, where p and q are the lengths of strings s and t respectively. For example, concatenation of "code" and "forces" is "codeforces".


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
        int n;
        cin >> n;
        vector<string> s(n);
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        string ans;
        set<string> st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j =0;j<s[i].length();j++){
                if(st.count(s[i].substr(0,j))==1 && st.count(s[i].substr(j))==1)  flag = 1;
            }
            if(flag)    ans+='1';
            else ans+='0';
        }
        cout<<ans<<endl;
    }

    return 0;
}