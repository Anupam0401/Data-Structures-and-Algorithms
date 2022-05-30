/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        // if(n == 2) return 2;
        int a = 1, b = 2;
        for(int i=3; i<=n; i++){
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
// @lc code=end

