/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        if (matchsticks.size() < 4 || sum % 4) return false;
        
        vector<int>visited(matchsticks.size(), false);
        return backtrack(matchsticks, visited, sum / 4, 0, 0, 4);
    }
    
    bool backtrack(vector<int>& matchsticks,vector<int>& visited, int target, int curr_sum, int i, int k) {
        if (k == 1) // if k == 1 then we found all subsets
            return true;
        
        if (curr_sum == target) // we found one subset, go on to the next one starting from curr_sum = 0
            return backtrack(matchsticks, visited, target, 0, 0, k-1);
        
        for (int j = i; j < matchsticks.size(); j++) {
            if (visited[j] || curr_sum + matchsticks[j] > target) continue; // if we visited this index already or curr_sum + matchsticks[j] > target then we can't use it
            
            visited[j] = true;
            if (backtrack(matchsticks, visited, target, curr_sum + matchsticks[j], j+1, k)) return true;
            visited[j] = false;
        }
        
        return false;
    }   
};
// @lc code=end

