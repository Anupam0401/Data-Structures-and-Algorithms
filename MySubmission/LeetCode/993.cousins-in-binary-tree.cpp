/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    int depth(TreeNode* root, int x, int h){
        if(root==nullptr)   return 0;
        if(root->val == x) return h;
        return depth(root->left,x,h+1) + depth(root->right,x,h+1);
    }
    bool isSiblings(TreeNode* root, int x, int y){
        //check if the parents of x and y are the same
        if(root==nullptr)   return false;
        if(root->left!=NULL && root->right!=NULL && ((root->left->val==x && root->right->val==y)||(root->left->val==y && root->right->val==x))) return true;
        return isSiblings(root->left,x,y) || isSiblings(root->right,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(x==y)    return false;
        int d1 = depth(root,x,0);
        int d2 = depth(root,y,0);
        cout<<d1<<" "<<d2<<endl;
        if(d1==d2 && !isSiblings(root,x,y)) return true;
        return false;
    }
};
// @lc code=end

