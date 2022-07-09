// You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

// The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

// You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

// Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long n = nums1.size();
        //make a max heap of absSum
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long maxSum = 0;
        for(int i=0;i<n;i++)
        {
            int absDiff = abs(nums1[i]-nums2[i]);
            pq.push(absDiff);
            maxSum += absDiff*absDiff;
        }
        int k = k1+k2;
        long long maxDiff = 0;
        while(k>0)
        {
            int x = pq.top();
            maxDiff+=x*x;
            pq.pop();
            x--;
            if(x>=0)
            {
                pq.push(x-1);
            }
            else break;
            maxDiff-=x*x;
            k--;
            if(maxDiff>=maxSum) return 0;
        }
        return maxSum-maxDiff;
    }
};