/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int height(TreeNode *root, int &maxSum)
    {
        if (root == NULL)
            return 0;
        int lh = max(0,height(root->left, maxSum));
        int rh = max(0,height(root->right, maxSum));
        maxSum = max(maxSum, lh + rh + root->val);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        height(root, maxSum);
        return maxSum;
    }
};
// @lc code=end
