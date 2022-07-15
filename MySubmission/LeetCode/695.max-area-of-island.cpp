/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
    int row,col;
public:
    // // recursive approach
    // int dfs_explore(int r,int c,vector<vector<int>>& grid){
    //     if(r<0 || c<0 || r>=row || c>=col || grid[r][c]==0) return 0;
    //     grid[r][c]=0;
    //     return 1 + dfs_explore(r+1,c,grid) + dfs_explore(r-1,c,grid) + dfs_explore(r,c+1,grid) + dfs_explore(r,c-1,grid);
    // }
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     row = grid.size();
    //     col = grid[0].size();
    //     int ans = 0;
    //     for(int i=0;i<row;i++){
    //         for(int j=0;j<col;j++){
    //             if(grid[i][j]==1){
    //                 ans = max(ans,dfs_explore(i,j,grid));
    //             }
    //         }
    //     } 
    //     return ans;
    // }

    // iterative approach
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> seen(row+1,vector<bool>(col+1,false));
        vector<int> dr({1,-1,0,0});
        vector<int> dc({0,0,-1,1});

        int ans = 0;
        for(int ri=0;ri<row;ri++){
            for(int ci=0;ci<col;ci++){
                if(grid[ri][ci]==1 && !seen[ri][ci]){
                    stack<vector<int>> st;
                    st.push({ri,ci});
                    seen[ri][ci]=true;
                    int shape = 0;
                    while(!st.empty()){
                        vector<int> node = st.top();
                        st.pop();
                        shape++;
                        for(int k=0;k<4;k++){
                            int i=node[0]+dr[k], j = node[1]+dc[k];
                            if(i>=0 && i<row && j>=0 && j<col && grid[i][j]==1 && !seen[i][j]){
                                st.push({i,j});
                                seen[i][j]=true;
                            }
                        }
                    }
                    ans = max(ans,shape);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

