#include<bits/stdc++.h>

/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        // for(int i=0;i<n;i++){
        //     if(envelopes[i][0] > envelopes[i][1])
        //         swap(envelopes[i][1], envelopes[i][0]);
        // }
        if(n<=1)    return n;
        sort(envelopes.begin(), envelopes.end());
        int ans = 1, x = envelopes[0][0], y = envelopes[0][1];
        for (int i = 1; i < n; i++)
        {
            if (envelopes[i][0] > x && envelopes[i][1] > y)
            {
                ans++;
                x = envelopes[i][0], y = envelopes[i][1];
            }
        }
        // int ansFromBack = 1;
        int ansFromBack = 1;
        x = envelopes[n-1][0], y = envelopes[n-1][1];
        for (int i = n-2; i >= 0; i--)
        {
            if (envelopes[i][0] < x && envelopes[i][1] < y)
            {
                ansFromBack++;
                x = envelopes[i][0], y = envelopes[i][1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << envelopes[i][0] << " " << envelopes[i][1] << endl;
        }
        return max(ans,ansFromBack);
    }
};
// @lc code=end
