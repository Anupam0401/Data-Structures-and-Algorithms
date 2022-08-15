/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    // bool isBalanced(TreeNode* root) {
    //     if(root==NULL)  return true;
    //     int lh = height(root->left);
    //     int rh = height(root->right);

    //     if(abs(lh-rh)>1)    return false;
    //     bool left = isBalanced(root->left);
    //     bool right = isBalanced(root->right);

    //     if(!left || !right) return false;
    //     return true;
    // }

    // O(n) time traversal
    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = dfsHeight(root->left);
        if (lh == -1)
            return -1;
        int rh = dfsHeight(root->right);
        if (rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return 1;
        return dfsHeight(root) != -1;
    }
};
// @lc code=end
