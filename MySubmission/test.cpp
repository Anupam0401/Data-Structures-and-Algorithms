// Given an array A of N integers.

// Find the count of the subarrays in the array which sums to zero. Since the answer can be very large, return the remainder on dividing the result with 10^9+7

int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int sum = 0;
    int count = 0;
    unordered_map<int, int> m;
    int mod = 1000000007;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
            count++;
        if (m.find(sum) != m.end())
        {
            count += m[sum];
        }
        m[sum]++;
    }
    return count % mod;
}
