/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // greedy approach
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int i=0, ans=0;
        while(i<n && truckSize>0){
            if(boxTypes[i][0]>=truckSize){
                ans+=boxTypes[i][1]*truckSize;
                break;
            }
            truckSize-=boxTypes[i][0];
            ans+=boxTypes[i][0]*boxTypes[i++][1];
        }
        return ans;
    }
};
// @lc code=end

