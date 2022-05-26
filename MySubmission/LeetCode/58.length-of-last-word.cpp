/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        int ans=0;
        for (int i = 0; i < s.length();i++) {
            if(s[i]!=32)    c++;
            else{
                ans=c==0?ans:c;
                c=0;
                // cout<<ans<<endl;
            }
        }
        ans=c==0?ans:c;
        return ans;
    }
};
// @lc code=end

