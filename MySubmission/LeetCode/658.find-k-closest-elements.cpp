/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n<=k)    return arr;
        // priority_queue<pair<int,int>> num_diff;
        // for(int i=0;i<k;i++){
        //     num_diff.push({abs(arr[i]-x),arr[i]});
        // }
        // sort(num_diff.begin(),num_diff.end(),[](const pair<int,int> &a, const pair<int,int> &b){
        //     if(a.second==b.second)   return a.first<b.first;
        //     return a.second<b.second;
        // });
        // for(int i=k;i<n;i++){
        //     int diff = num_diff.top().first;
        //     if(abs(arr[i]-x)<diff){
        //         num_diff.pop();
        //         num_diff.push({abs(arr[i]-x),arr[i]});
        //     }
        // }
        // vector<int> ans;
        // for(int i=0;i<k;i++){
        //     ans.push_back(num_diff.top().second);
        //     num_diff.pop();
        // }
        // sort(ans.begin(),ans.end());
        // return ans;

        int sum = 0;
        for(int i=0;i<k;i++)    sum+=abs(arr[i]-x);
        pair<int,int> window = {0,k-1};
        int m = sum;
        for(int i=1;i<=n-k;i++){
            sum-=abs(arr[i-1]-x);
            sum+=abs(arr[i+k-1]-x);
            if(sum<m){
                m = sum;
                window = {i,i+k-1};
            }
        }
        vector<int> ans;
        int i=window.first, j=window.second;
        for(int p=i;p<=j;p++)   ans.push_back(arr[p]);
        return ans;
    }
};
// @lc code=end

