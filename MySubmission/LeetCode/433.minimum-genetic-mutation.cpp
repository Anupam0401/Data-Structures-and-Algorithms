/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        if(!st.count(end))  return -1;
        queue<string> q;
        q.push(start);
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr==end)   return ans;
                st.erase(curr);
                for(int i=0;i<8;i++){
                    string temp = curr;
                    //ACGT
                    temp[i] = 'A';
                    if(st.count(temp))  q.push(temp);
                    temp[i] = 'C';
                    if(st.count(temp))  q.push(temp);
                    temp[i] = 'G';
                    if(st.count(temp))  q.push(temp);
                    temp[i] = 'T';
                    if(st.count(temp))  q.push(temp);
                }
            }
            ans++;
        }
        return -1;
    }
};
// @lc code=end

