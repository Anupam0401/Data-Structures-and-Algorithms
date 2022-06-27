/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if(root==nullptr)   return res;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(true){
            if(temp!=NULL){
                st.push(temp);
                temp = temp->left;
            }
            else{
                if(st.empty())  break;
                temp = st.top();
                st.pop();
                res.push_back(temp->val);
                temp = temp->right;
            }
        }
        return res;
    }
};
// @lc code=end
