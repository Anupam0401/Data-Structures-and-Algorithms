// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// You can assume that you can always reach the last index.

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        int i = 0, j = 0, k = 0;
        while (j < n - 1)
        {
            int max_jump = 0;
            int max_index = 0;
            for (int l = i; l <= j; l++)
            {
                if (l + nums[l] > max_jump)
                {
                    max_jump = l + nums[l];
                    max_index = l;
                }
            }
            i = max_index + 1;
            j = max_index + nums[max_index];
            k++;
        }
        return k;
    }
};