/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return buildBST(preorder, ind, INT_MAX);
    }
    TreeNode* buildBST(vector<int>& preorder, int& i, int upper_limit){
        if(i==preorder.size() || preorder[i]>upper_limit)   return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = buildBST(preorder,i,root->val);
        root->right = buildBST(preorder,i,upper_limit);
        return root;    
    }
};
// @lc code=end

