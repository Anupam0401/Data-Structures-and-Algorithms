// You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

// You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

// Trim each number in nums to its rightmost trimi digits.
// Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
// Reset each number in nums to its original length.
// Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.

// Note:

// To trim to the rightmost x digits means to keep removing the leftmost digit, until only x digits remain.
// Strings in nums may contain leading zeros.


class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int k = queries[i][0], trim = queries[i][1];
            map<int,int> m;
            for(int j=0;j<n;j++){
                int len = nums[j].size();
                int num;
                if(len<=trim) num = stoi(nums[j]);
                else num = stoi(nums[j].substr(len-trim));
                m[num] = j;
            }
            // get the index of k-th smallest element in m
            int cnt = 0;
            int ind = 0;
            for(auto it=m.begin();it!=m.end();it++){
                cnt++;
                if(cnt==k){
                    ind = it->second;
                    break;
                }
            }
            ans[i] = ind;
        }
        return ans;
    }
};
