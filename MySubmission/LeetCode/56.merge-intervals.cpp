/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1)    return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<n;i++){
            while(ans[j][1]>=intervals[i][0]){
                ans[j][1] = max(ans[j][1],intervals[i][1]);
                i++;
            }
            ans.push_back(intervals[i]);
            j++;
        }
        return ans;
    }
};
// @lc code=end

