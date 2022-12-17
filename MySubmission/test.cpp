// There are N clerks who sit on a long working bench. Their productivity is relative to their position in the bench.
// Benches are labelled from 1 to N from left to right.
// Each clerk's productivity is calculated by two factors A and B.
// It is given that the ith clerk's productivity at position j is calaculated as :
// {A[i] *(j-1) + B[i]*(N-j)}.
// Task is to find the maximum productivity of the bench.
// Return answer modulo 10^9+7.

int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({A[i],B[i]});
    }
    sort(v.begin(),v.end());
    vector<int> pre(n,0);
    vector<int> suf(n,0);
    pre[0] = v[0].first;
    suf[n-1] = v[n-1].second;
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + v[i].first;
    }
    for(int i=n-2;i>=0;i--){
        suf[i] = suf[i+1] + v[i].second;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int temp = pre[i] + suf[i];
        ans = max(ans,temp);
    }
    return ans;
}