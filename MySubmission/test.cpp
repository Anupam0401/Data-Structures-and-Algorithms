// You are given an integer array A of n distinct integers
// In one jump, you can travel from ith index to jth index or jth to ith only if GCD(a[i],a[j])>1

// Return 1 if for all pairs of (i,j) starting from index i can you travel to index j in some finite number of jumps else, return 0.

int gcd(int a,int b){
    if(a==0)    return b;
    return gcd(b%a,a);
}

int Solution::solve(vector<int> &a) {
    int n = a.size();
    sort(a.begin(),a.end(),);
    vector<int> dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(gcd(a[i],a[j])>1)
                dp[i] = max(dp[i],dp[j]+1);
        }
    }
    return *max_element(dp.begin(),dp.end());
}
