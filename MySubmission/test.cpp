// Given an array of positive integers A and an integer B, find and return first continuous subarray which adds to B.

// If the answer does not exist return an array with a single element "-1".

// First sub-array means the sub-array for which starting index in minimum.

vector<int> Solution::solve(vector<int> &A, int B) {
    int i=0,j=0,n=A.size();
    long long sum=A[0];
    while(j<n && i<=j){
        if(sum==B){
            vector<int> ans;
            for(int k=i;k<=j;k++){
                ans.push_back(A[k]);
            }
            return ans;
        }
        else if(sum<B){
            j++;
            if(j<n)
                sum+=A[j];
        }
        else{
            sum-=A[i];
            i++;
            if(i>j && i<n-1){
                j++;
                sum+=A[j];
            }
        }
    }
    vector<int> ans;
    ans.push_back(-1);
    return ans;
    
}
