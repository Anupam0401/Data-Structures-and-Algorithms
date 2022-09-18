/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        unordered_map<int, int> in_mp;
        for (int i = 0; i < n; i++)
            in_mp[inorder[i]] = i;
        // reverse(postorder.begin(),postorder.end());
        return makeTree(0, n - 1, inorder, 0, n - 1, postorder, in_mp);
    }
    TreeNode *makeTree(int inStart, int inEnd, vector<int> &inorder, int postStart, int postEnd, vector<int> &postorder, unordered_map<int, int> &in_mp)
    {
        if (inStart > inEnd)
            return NULL;
        if (inStart == inEnd)
            return new TreeNode(inorder[inStart]);
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int in_root = in_mp[postorder[postEnd]];
        int left_size = in_root - inStart;
        root->left = makeTree(inStart, in_root - 1, inorder, postStart, postStart + left_size - 1, postorder, in_mp);
        root->right = makeTree(in_root + 1, inEnd, inorder, postStart + left_size, postStart - 1, postorder, in_mp);
        return root;
    }
};
// @lc code=end
