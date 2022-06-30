/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)    return 0;
        if(n==1 ||n==2) return 1;
        int a=0,b=1,c=1;
        for(int i=3;i<=n;i++){
            c=a+b+c;
            b=c-a-b;
            a=c-b-a;
        }
        return c;
    }
};
// @lc code=end

