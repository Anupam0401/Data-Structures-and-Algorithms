/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;
        while(l<r){
            long long mid = (l+r)/2;
            if(isBadVersion(mid)) r = mid;
            else l = mid+1;
        }
        return (int)l;
    }
};
// @lc code=end

