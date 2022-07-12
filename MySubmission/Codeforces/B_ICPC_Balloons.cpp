// In an ICPC contest, balloons are distributed as follows:

// Whenever a team solves a problem, that team gets a balloon.
// The first team to solve a problem gets an additional balloon.
// A contest has 26 problems, labelled A, B, C, ..., Z. You are given the order of solved problems in the contest, denoted as a string s, where the i-th character indicates that the problem si has been solved by some team. No team will solve the same problem twice.
// Determine the total number of balloons that the teams recieved. Note that some problems may be solved by none of the teams.

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
        string s;
        cin >> s;
        vector<char> occurence(26,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(occurence[s[i]-'A']==0){
                ans+=2;
            }
            else    ans+=1;
            occurence[s[i]-'A']++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
