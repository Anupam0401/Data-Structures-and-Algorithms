/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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

// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
class Solution {
public:
    void getRightView(TreeNode* root, vector<int>& ans, int depth){
        if(!root) return;
        if(depth==ans.size())   ans.push_back(root->val);
        getRightView(root->right, ans, depth+1);
        getRightView(root->left, ans, depth+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)   return {};
        vector<int> ans;
        getRightView(root,ans,0);
        return ans;
    }
};
// @lc code=end

