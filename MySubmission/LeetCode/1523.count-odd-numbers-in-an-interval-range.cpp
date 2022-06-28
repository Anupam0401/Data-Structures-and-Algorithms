/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
    bool isOdd(int x){
        return x&1;
    }
    int countOdds(int low, int high) {
        int ans=0;
        if(isOdd(low) and isOdd(high)){
            ans = (high-low+2)/2;
        }
        else if(isOdd(low) or isOdd(high)){
            ans = (high-low+1)/2;
        }
        else{
            ans = (high-low)/2;
        }
        return ans;
    }
};
// @lc code=end

