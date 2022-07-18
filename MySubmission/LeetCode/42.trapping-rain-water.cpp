/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3)
            return 0;
        
        // O(n) space
        // vector<int> left(n,0);
        // vector<int> right(n,0);
        // left[0] = height[0];
        // right[n-1] = height[n-1];
        // for(int i=1;i<n;i++){
        //     left[i]=max(left[i-1],height[i]);
        // }
        // for(int i=n-2;i>=0;i--){
        //     right[i] = max(right[i+1],height[i]);
        // }
        // int res = 0;
        // for(int i=1;i<n-1;i++){
        //     res+=min(left[i],right[i])-height[i];
        // }
        // return res;

        //O(1) space
        int left = 0, right = n - 1;
        int max_left = 0, max_right = 0;
        int result = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= max_left)
                    max_left = height[left];
                else
                    result += max_left - height[left];
                left++;
            }
            else
            {
                if (height[right] >= max_right)
                    max_right = height[right];
                else
                    result += max_right - height[right];
                right--;
            }
        }
        return result;
    }
};
// @lc code=end

