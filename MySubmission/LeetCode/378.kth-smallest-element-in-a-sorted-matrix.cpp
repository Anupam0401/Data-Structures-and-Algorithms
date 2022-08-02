/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // if(k==1)    return matrix[0][0];
        // int n = matrix.size();
        // vector<int> ptr(n,0);
        // vector<bool> check(n,true);
        // int count = 1;
        // int row = 0;
        // while(count<k){
        //     int minElement = INT_MAX;
        //     for(int i=0;i<n;i++){
        //         if(check[i] && matrix[i][ptr[i]]<=minElement){
        //             minElement = matrix[i][ptr[i]];
        //             row = i;
        //         }
        //     }
        //     if(ptr[row]>=n) check[row]=false;
        //     else
        //         ptr[row]++;
        //     count++;
        // }
        // int res = INT_MAX;
        // for(int i=0;i<n;i++){
        //     res = min(res,matrix[i][ptr[i]]);
        // }
        // return res;


        // done using priority queue in O(k) space and O(n^2) time
        // int n = matrix.size();
        // priority_queue<int> q;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         q.push(matrix[i][j]);
        //         if(q.size()>k)  q.pop();
        //     }
        // }
        // return q.top();

        // done using binary search in O(n^2) time and O(1) space
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while(left<right){
            int mid = left+(right-left)/2;
            int count = 0;
            for(int i=0;i<n;i++){
                int j = upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                count+=j;
            }
            if(count<k) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
// @lc code=end

