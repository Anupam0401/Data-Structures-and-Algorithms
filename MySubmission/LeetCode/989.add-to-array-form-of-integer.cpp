/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
public:
//using extra memory
    // vector<int> addToArrayForm(vector<int>& num, int k) {
    //     int n = num.size();
    //     int i = n-1;
    //     int carry = 0, sum = 0;
    //     vector<int> res;
    //     while(i>=0 || k>0){
    //         sum = carry;
    //         if(i>=0){
    //             sum += num[i];
    //             i--;
    //         }
    //         if(k>0){
    //             sum += k%10;
    //             k = k/10;
    //         }
    //         carry = sum/10;
    //         sum = sum%10;
    //         res.push_back(sum);
    //     }
    //     if(carry)   res.push_back(carry);
    //     reverse(res.begin(),res.end());
    //     return res;
    // }

    // O(1) space
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i = num.size()-1;i>=0 && k>0; --i){
            num[i] += k;
            k = num[i]/10;
            num[i] = num[i]%10; 
        }
        while(k){
            num.insert(num.begin(),k%10);
            k/=10;
        }
        return num;
    }
};
// @lc code=end

