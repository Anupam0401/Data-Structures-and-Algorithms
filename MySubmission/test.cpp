// You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.

// Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.

// Note that an integer x divides y if y % x == 0.

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size();
        int m = numsDivide.size();
        // find the gcd of elements in numsDivide
        int g = numsDivide[0];
        for(int i=1; i<m; i++){
            g = gcd(g, numsDivide[i]);
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        bool flag = 0;
        for(int i=0; i<n; i++){
            if(g%nums[i]!=0)  ans++;
            else{
                flag=1;
                break;
            }
        }
        return flag?ans:-1;
    }
};