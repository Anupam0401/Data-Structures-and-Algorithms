// Given an array A of integers and two integers B and C.
// Find out the number of wonderful subarrays.
// An array is a wonderful subarray if the following condition hold:
// B*sum of elements of subarray = C*length of subarray.

long Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size();
    long long int sum = 0;
    long long int ans = 0;
    unordered_map<long long int, long long int> m;
    m[0] = 1;
    for(int i = 0; i < n; i++){
        sum += A[i];
        long long int x = (B*sum - C*(i+1));
        if(m.find(x) != m.end()){
            ans += m[x];
        }
        m[x]++;
    }
    return ans;
}