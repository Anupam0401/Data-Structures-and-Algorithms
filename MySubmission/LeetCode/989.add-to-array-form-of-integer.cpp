/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n-1;
        int carry = 0, sum = 0;
        vector<int> res;
        while(i>=0 || k>0){
            sum = carry;
            if(i>=0){
                sum += num[i];
                i--;
            }
            if(k>0){
                sum += k%10;
                k = k/10;
            }
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum);
        }
        if(carry)   res.push_back(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

