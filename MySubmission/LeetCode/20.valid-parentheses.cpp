/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            // push to the stack in case of opening braces of any type
            if(s[i]=='('||s[i]=='['||s[i]=='{')   st.push(s[i]);

            // check for the top element in each case and pop if found its pair
            else if(s[i]==')' && !st.empty() && st.top()=='(')  st.pop();
            else if(s[i]==']' && !st.empty() && st.top()=='[')  st.pop();
            else if(s[i]=='}' && !st.empty() && st.top()=='{')  st.pop();

            //otherwise
            else return false;
        }
        return st.empty(); // if stack is not empty, that implies that some element was left unpaired
    }
};
// @lc code=end

