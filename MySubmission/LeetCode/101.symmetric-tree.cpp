/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool check_symmetry(TreeNode *leftst, TreeNode *rightst)
    {
        if (leftst == NULL || rightst == NULL)
            return leftst == rightst;
        if (leftst->val != rightst->val)
            return false;
        return check_symmetry(leftst->left, rightst->right) && check_symmetry(leftst->right, rightst->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return check_symmetry(root->left, root->right);
    }
};
// @lc code=end
