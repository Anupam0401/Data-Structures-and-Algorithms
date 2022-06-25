// You are given a 0-indexed integer array nums. In one operation, select any non-negative integer x and an index i, then update nums[i] to be equal to nums[i] AND (nums[i] XOR x).

// Note that AND is the bitwise AND operation and XOR is the bitwise XOR operation.

// Return the maximum possible bitwise XOR of all elements of nums after applying the operation any number of times.

class Solution {
public:
    int maximumXOR(vector<int>& nums) { // do it in O(n log n)
        int n = nums.size();
        if(n==1)    return nums[0];
        int ans = 0;
        for(int i=31; i>=0; i--){
            ans |= (1<<i);
            set<int> s;
            for(int j=0; j<n; j++){
                s.insert(nums[j]&ans);
            }
            int tmp = ans;
            ans = 0;
            for(int x: s){
                ans = max(ans, x^tmp);
            }
        }
    }
};