/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> helper;
        int i=0,j=0;
        int n = pushed.size();
        while(i<n||j<n){
            if(!helper.empty() && popped[j]==helper.top()){
                helper.pop();
                j++;
            }
            else{
                if(i>n) return false;
                helper.push(pushed[i]);
                i++;
            }
        }
        if(helper.empty())  return true;
        else return false;
    }
};
// @lc code=end

