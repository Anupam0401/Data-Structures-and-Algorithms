/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result = result << 1; // extract the last bit of n and append it to result
            result = result | (n & 1); // extract the last bit of n and append it to result
            n = n >> 1; // remove the last bit of n
        }
        return result;
    }
};
// @lc code=end

// 00000010100101000001111010011101
// 00000000000000000000000000000000
// 00000000000000000000000000000001
// 