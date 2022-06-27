/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int source, int color, int r, int c){
        if(sr<0 || sr>=r || sc<0 || sc>=c)  return;
        if(image[sr][sc]!=source)   return;
        image[sr][sc] = color;

        dfs(image,sr+1,sc,source,color,r,c);
        dfs(image,sr,sc+1,source,color,r,c);
        dfs(image,sr-1,sc,source,color,r,c);
        dfs(image,sr,sc-1,source,color,r,c);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]) return image;
        int r = image.size(), c = image[0].size();
        dfs(image,sr,sc,image[sr][sc],color,r,c);
        return image;
    }
};
// @lc code=end
