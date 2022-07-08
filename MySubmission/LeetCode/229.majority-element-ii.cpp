/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int n1 = -1, n2 = -1, c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == n1)
                c1++;
            else if (nums[i] == n2)
                c2++;
            else if (c1 == 0)
            {
                n1 = nums[i];
                c1++;
            }
            else if (c2 == 0)
            {
                n2 = nums[i];
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        if (n1 == n2)
        {
            ans.push_back(n1);
            return ans;
        }
        c1 = 0, c2 = 0;
        for (auto x : nums)
        {
            if (x == n1)
                c1++;
            if (x == n2)
                c2++;
        }
        if (c1 > n / 3)
            ans.push_back(n1);
        if (c2 > n / 3)
            ans.push_back(n2);
        return ans;
    }
};
// @lc code=end
