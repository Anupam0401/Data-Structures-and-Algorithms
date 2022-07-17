/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> stk;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            ans[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }
        return ans;
    }
};
// @lc code=end

