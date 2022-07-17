/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry=0;
        string ans = "";
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0){
                sum+=a[i--]-'0';
            }
            if(j>=0){
                sum+=b[j--]-'0';
            }
            ans=(char)(sum%2+'0')+ans;
            carry = sum/2;
        }
        if(carry!=0)    ans=(char)(carry+'0')+ans;
        return ans;
    }
};
// @lc code=end

