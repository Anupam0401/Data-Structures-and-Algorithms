/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        int m = 2;
        sort(people.begin(),people.end(),comp);
        vector<vector<int>> ans(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            int count = people[i][1];
            for(int j=0;j<n;j++){
                if(count == 0 and ans[j][0]==-1){
                    ans[j][0] = people[i][0];
                    ans[j][1] = people[i][1];
                    break;
                }
                else if(ans[j][0]==-1 || ans[j][0]>=people[i][0]){
                    count--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

