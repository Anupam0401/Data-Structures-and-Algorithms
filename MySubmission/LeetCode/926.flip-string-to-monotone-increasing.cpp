/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start

// A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

// You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

// Return the minimum number of flips to make s monotone increasing.

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int flipCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                flipCount++;
            }
            dp[i] = flipCount;
        }
        int minFlip = INT_MAX;
        for (int i = 0; i < n; i++) {
            int flip = dp[i] + (n - i - 1 - (dp[n - 1] - dp[i]));
            minFlip = min(minFlip, flip);
        }
        return minFlip;
    }
};
// @lc code=end

