/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int super = haystack.length(), sub = needle.size();
        if(sub>=super)  return haystack == needle ? 0 : -1;
        int j = 0;
        for(int i=0;i<super;i++){
            int temp = i;
            while(haystack[i] == needle[j]){
                if(j==sub-1)    return temp;
                i++;
                j++;
            }
            j=0;
            i=temp;
        }
        return -1;
    }
};
// @lc code=end

