/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        for(int i=0;i<n-1;i++){
            sort(stones.begin(),stones.end());
            stones[n-1]-=stones[n-2];
            stones[n-2]=0;
        }
        // for(int i=0;i<n;i++){
        //     cout<<stones[i]<<" ";
        // }
        return stones[n-1];
    }
};
// @lc code=end

