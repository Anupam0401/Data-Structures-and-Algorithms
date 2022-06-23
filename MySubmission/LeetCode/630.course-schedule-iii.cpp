/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[1]==b[1])  return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        if(n==1)    return courses[0][0]<=courses[0][1];
        sort(courses.begin(),courses.end(),comp);
        // for(int i=0;i<n;i++){
        //     cout<<courses[i][0]<<" "<<courses[i][1]<<endl;
        // }
        int totalTimeTillNow = 0,count = 0; 
        int maxDuration = courses[0][0],secondMax = 0;
        for(int i=0;i<n;i++){
            if(courses[i][0]>courses[i][1])  continue;
            if(totalTimeTillNow+courses[i][0]<=courses[i][1]){
                count++;
                totalTimeTillNow+=courses[i][0];
                if(i==2){
                    secondMax = min(courses[i][0],courses[i-1][0]);
                }
                maxDuration = max(maxDuration,courses[i][0]);
            }
            else{
                if(maxDuration>=courses[i][0]){
                    totalTimeTillNow+=courses[i][0]-maxDuration;
                    maxDuration = max(maxDuration,courses[i][0]);
                }
            }
        }
        return 0;
    }
};
// @lc code=end

