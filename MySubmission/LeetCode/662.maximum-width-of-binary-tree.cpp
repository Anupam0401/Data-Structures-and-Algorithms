/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return 0;
        queue<pair<TreeNode*,long int>> q;
        q.push({root,0});
        int ans = INT_MIN;
        while(!q.empty()){
            int n = q.size();
            long int curMin = q.front().second;
            int l=0,r=0;
            for(int i=0;i<n;i++){
                long int cur_id = q.front().second-curMin;
                TreeNode* front = q.front().first;
                q.pop();
                if(i==0)    l = cur_id;
                if(i==n-1)  r = cur_id;
                if(front->left) q.push({front->left,cur_id*2+1});
                if(front->right)    q.push({front->right,cur_id*2+2}); 
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
// @lc code=end

