/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if(n==1)    return stoi(tokens[0]);
        stack<int> st;
        for(auto op : tokens){
            if(op == "+" || op == "-" || op == "*" || op == "/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                if(op=="+") st.push(x+y);
                else if(op=="-")    st.push(y-x);
                else if(op=="/")    st.push(y/x);
                else st.push(x*y);
            }
            else st.push(stoi(op));
        }
        return st.top();
    }
};
// @lc code=end

