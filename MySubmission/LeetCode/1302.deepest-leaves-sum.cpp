/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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

// Given the root of a binary tree, return the sum of values of its deepest leaves.
class Solution {
public:
    void dfs(TreeNode* root, int& depth) {
        if (!root) return;
        if (!root->left && !root->right) {
            depth++;
            return;
        }
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 0;
        dfs(root, depth);
        return depth;
    }
    void dfs_n(TreeNode* root, int depth, int& res) {
        if (!root) return;
        // check  if the height of the node is the same as the max depth
        if (depth == maxDepth(root)) {
            res += root->val;
            return;
        }
        dfs_n(root->left, depth, res);
        dfs_n(root->right, depth, res);
    }
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        // find the max depth of the tree
        int depth = 0;
        depth = maxDepth(root);
        // find the deepest leaves
        // vector<int> leaves;
        dfs_n(root, depth, 0);
        return res;
    }
};
// @lc code=end

