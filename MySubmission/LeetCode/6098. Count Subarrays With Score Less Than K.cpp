// The score of an array is defined as the product of its sum and its length.

// For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
// Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

// A subarray is a contiguous sequence of elements within an array.

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        long long ans=0;
        long long sum=0;
        long long count=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum>=k){
                ans+=count;
                sum-=nums[i-count];
                count=0;
            }
            else{
                count++;
            }
        }
        return ans;
    }
};