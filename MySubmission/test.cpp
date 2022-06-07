// Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.


class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0; i <= k; i++){
            pq.push(arr[i]);
        }
        vector<int> ans;
        for(int i = k+1; i < num; i++){
            ans.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        while(pq.size() > 0){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};