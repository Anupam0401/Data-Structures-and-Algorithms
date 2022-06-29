/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        if(n==1)    return 0;
        sort(s.begin(),s.end());
        vector<int> unused_freq;
        unused_freq.push_back(0);
        char c = s[0];
        int count = 1;
        for(int i=1;i<n;i++){
            while(s[i]==c){
                count++;
                i++;
            }
            if(s[i]!=c){
                unused_freq.push_back(count);
                c=s[i];
                count=1;
            }
        }
    }
};
// @lc code=end

