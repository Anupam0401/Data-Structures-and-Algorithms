/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            int sum = 0;
            int num = i;
            while(num){
                sum+=num%2;
                num/=2;
            }
            ans[i]=sum;
        }
        return ans;
    }
};
// @lc code=end

