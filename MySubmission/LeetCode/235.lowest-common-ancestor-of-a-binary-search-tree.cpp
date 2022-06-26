/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
    void getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path, bool found) {
        if(root == nullptr) return;
        path.push_back(root);
        if(root == target) {
            found = true;
            return;
        }
        getPath(root->left, target, path, found);
        if(found) return;
        getPath(root->right, target, path, found);
        if(found) return;
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathOfP;
        vector<TreeNode*> pathOfQ;
        getPath(root, p, pathOfP,0);
        getPath(root, q, pathOfQ,0);
        int i = 0;
        while(i<pathOfP.size() && i<pathOfQ.size() && pathOfP[i] == pathOfQ[i]) i++;
        // cout<< pathOfP[i-1] <<endl;
        return pathOfP[i-1];
    }
};
// @lc code=end

