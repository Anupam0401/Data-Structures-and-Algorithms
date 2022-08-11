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
    // done using iterative approach -- using stack
    // vector<int> inorderTraversal(TreeNode *root)
    // {
    //     vector<int> res;
    //     if(root==nullptr)   return res;
    //     stack<TreeNode*> st;
    //     TreeNode* temp = root;
    //     while(true){
    //         if(temp!=NULL){
    //             st.push(temp);
    //             temp = temp->left;
    //         }
    //         else{
    //             if(st.empty())  break;
    //             temp = st.top();
    //             st.pop();
    //             res.push_back(temp->val);
    //             temp = temp->right;
    //         }
    //     }
    //     return res;
    // }

    // Morris Traversal -- in O(n) time and O(1) space
    vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode* curr = root;
        vector<int> res;
        while(curr!=NULL){
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};
// @lc code=end
