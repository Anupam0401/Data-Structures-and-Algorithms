/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')   stk.push(i);
            else if(s[i]==')'){
                if(stk.empty()) s[i]='-';
                else    stk.pop();
            }
        }
        while(!stk.empty()){
            s[stk.top()]='-';
            stk.pop();
        }
        for(int i=0;i<s.length();i++){
            if(s[i]!='-')   res+=s[i];
        }
        return res;
    }
};
// @lc code=end

