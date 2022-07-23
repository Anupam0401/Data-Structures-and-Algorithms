// Given an integer array nums, return the number of subarrays filled with 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int n = nums.size();
        long long int count = 0;
        for(long long int i=0;i<n;i++)    
            if(nums[i]==0){
                count++;
            }
        if(count==0)
            return 0;
        if(count==n)    return (long long)n*(n+1)/2;
        long long int ans = 0;
        long long int i=0;
        while(i<n)
        {
            if(nums[i]==0)
            {
                count=0;
                while(i<n && nums[i]==0)
                {
                    i++;
                    count++;
                }
                ans+=count*(count+1)/2;
            }
            else
                i++;
        }
        return ans;
    }
};

