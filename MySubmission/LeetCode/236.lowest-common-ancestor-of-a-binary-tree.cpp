/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void get_path(vector<TreeNode*>& path,TreeNode* root,TreeNode* x){
        if(root==x) return;
        if(root->left) get_path(path,root->left,x);
        if(root->right) get_path(path,root->right,x);
        path.push_back(root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathOfP;
        vector<TreeNode*> pathOfQ;
        get_path(pathOfP,root,p);
        get_path(pathOfQ,root,q);
        int i=0,j=0;
        while(pathOfP[i]==pathOfQ[j]){
            i++;
            j++;
        }
        return pathOfP[i-1];
    }
};
// @lc code=end

