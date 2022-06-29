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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        // using stack
        if (root->left == NULL || root->right == NULL)
            return root->left == root->right;
        stack<TreeNode *> st;
        if (root->left->val != root->right->val)
            return false;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            if(st.size()%2!=0)  return false;
            TreeNode *rsubtree = st.top();
            st.pop();
            TreeNode *lsubtree = st.top();
            st.pop();
            if(lsubtree==NULL or rsubtree==NULL)    return lsubtree == rsubtree;
            else if(lsubtree->val!=rsubtree->val)   return false;
            if(lsubtree->left!=NULL){
                if(rsubtree->right==NULL)   return false;
                st.push(lsubtree->left);
                st.push(rsubtree->right);
            }
            else if(rsubtree->right!=NULL)  return false;
            if(lsubtree->right!=NULL){
                if(rsubtree->left==NULL)    return false;
                st.push(lsubtree->right);
                st.push(rsubtree->left);
            }
            else if(rsubtree->left!=NULL)   return false;
        }
        return true;
    }
};
// @lc code=end
