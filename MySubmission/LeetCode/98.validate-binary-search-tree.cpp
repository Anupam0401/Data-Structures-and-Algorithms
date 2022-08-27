/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    //  done using inorder traversal and validation of the the traversal formed
    // void inorderTraversal(TreeNode* root, vector<int>& inorder){
    //     if(root == nullptr) return;
    //     inorderTraversal(root->left, inorder);
    //     inorder.push_back(root->val);
    //     inorderTraversal(root->right, inorder);
    // }
    // bool isValidBST(TreeNode* root) {
    //     vector<int> inorder;
    //     inorderTraversal(root, inorder);
    //     for(int i=0;i<inorder.size()-1;i++){
    //         if(inorder[i]>= inorder[i+1]) return false;
    //     }
    //     return true;
    // }

    bool isValidBST(TreeNode* root, long low = LONG_MIN, long high = LONG_MAX){
        if(root == NULL)    return true;
        if(root->val<=low || root->val>=high) return false;
        return isValidBST(root->left,low,root->val) and isValidBST(root->right,root->val,high);

    }
};
// @lc code=end

