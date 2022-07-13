/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution
{
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int total = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && (long long int)nums[i] > 2 * (long long int) nums[j])
            {
                j++;
            }
            total += (j - (mid + 1));
        }

        vector<int> t;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {

            if (nums[left] <= nums[right])
            {
                t.push_back(nums[left++]);
            }
            else
            {
                t.push_back(nums[right++]);
            }
        }

        while (left <= mid)
        {
            t.push_back(nums[left++]);
        }
        while (right <= high)
        {
            t.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            nums[i] = t[i - low];
        }
        return total;
    }
    int customMerge(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;
        int inv = customMerge(nums, low, mid);
        inv += customMerge(nums, mid + 1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        return customMerge(nums, 0, n - 1);
    }
};
// @lc code=end
