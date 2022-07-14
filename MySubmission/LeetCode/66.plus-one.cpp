/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        // if(n==1 && digits[0]==9){
        //     digits.push_front(1);
        //     return digits;
        // }
        // vector<int> result;
        // result.push_back((digits[n-1]+1)%10);
        // int carry = (digits[n-1]+1)/10;
        int carry = (digits[n-1]+1)/10;
        digits[n-1] = (digits[n-1]+1)%10;
        for(int i=n-2;i>=0 && carry>0;i--){
            int temp = digits[i];
            digits[i] = (digits[i]+carry)%10;
            carry = (temp+carry)/10;
        }
        if(carry>0)  {
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
// @lc code=end

