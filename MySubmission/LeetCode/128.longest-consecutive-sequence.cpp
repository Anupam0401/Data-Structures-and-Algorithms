/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return n;
        set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(nums[i]);
        int count = 1;
        // first element in set
        int prev = *s.begin();
        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout<<*it<<endl;
            int temp = 0;
            while (*it == prev + 1)
            {
                prev = *it;
                temp++;
                it++;
                if (it == s.end())
                    break;
            }
            count = max(count, temp + 1);
            prev = *it;
            if (it == s.end())
                break;
        }
        return count;
    }
};
// @lc code=end
