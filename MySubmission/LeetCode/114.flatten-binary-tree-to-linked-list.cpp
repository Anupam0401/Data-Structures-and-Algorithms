/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
private:
    vector<int> store;
public:
    // void preorder(TreeNode* root){
    //     if(!root)   return;
    //     store.push_back(root->val);
    //     preorder(root->left);
    //     preorder(root->right);
    // }
    // void flatten(TreeNode* root) {
    //     TreeNode* res = new TreeNode(0);
    //     TreeNode *temp = res;
    //     preorder(root);
    //     for(auto x:store){
    //         res->right = new TreeNode(x);
    //         res = res->right;
    //     }
    //     root = temp->right;

    // }
    void flatten(TreeNode *root) {
		TreeNode*now = root;
		while (now)
		{
			if(now->left)
			{
                //Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};
// @lc code=end

