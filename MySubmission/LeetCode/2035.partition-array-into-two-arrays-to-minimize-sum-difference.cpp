/*
 * @lc app=leetcode id=2035 lang=cpp
 *
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
 */

// @lc code=start
class Solution
{
public:
    int tabulation(int n, int sum,vector<int> &nums){
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int row = 0; row < n; row++)
        {
            dp[row][0] = true;
        }
        if (nums[0] <= sum)
            dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int t = 1; t <= sum; t++)
            {
                bool not_take = dp[i - 1][t];
                bool take = false;
                if (nums[i] <= t)
                    take = dp[i - 1][t - nums[i]];
                dp[i][t] = not_take || take;
            }
        }
        int minDifference = INT_MAX;
        int lastRow = n - 1;
        for (int col = 0; col <= sum/2 + 1; col++)
        {
            if (dp[lastRow][col] == true)
            {
                int counter_sum = sum - col;
                int abs_diff = abs(col-counter_sum);
                cout<<abs_diff<<" ";
                minDifference = min(minDifference, abs_diff);
            }
            // cout<<dp[lastRow][col]<<" ";
        }
        return minDifference;
    }
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int minElement = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            minElement = min(minElement,nums[i]);
        }
        if(minElement<0){
            minElement = -minElement;
            sum=0;
            for (int i = 0; i < n; i++)
            {    
                nums[i]+=minElement;
                sum+=nums[i];
            }
        }
        return tabulation(n,sum,nums);
    }
};
// @lc code=end
