// You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

// Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

class Solution
{
public:
    int getSumDigit(int num)
    {
        int sum = 0;
        while (num)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int> &nums)
    {
        int res = -1, d_n[82] = {}; // 9 * 9
        for (int n : nums)
        {
            int d = getSumDigit(n);
            if (d_n[d])
                res = max(res, d_n[d] + n);
            d_n[d] = max(d_n[d], n);
        }
        return res;
    }
};