// Description
// Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

// Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

// The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

// The right-most node is also defined by the same way with left and right exchanged.

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    bool isLeaf(TreeNode *node){
        if(node==NULL)  return false;
        if(node->left==NULL and node->right==NULL)  return true;    
    }
    void preorder(TreeNode* root, vector<int>& pre){
        if(root==NULL)  return;
        if(isLeaf(root))    pre.push_back(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        vector<int> res;
        if(root==NULL)   return NULL;
        TreeNode* temp = root;
        while(!isLeaf(temp)){
            res.push_back(temp->val);
            if(temp->left==NULL)    temp = temp->right;
            else temp = temp->left;
        }
        preorder(root,res);
        stack<int> stk;
        while(!isLeaf(root)){
            res.push_back(root->val);
            if(root->right==NULL)    root = root->left;
            else root = root->right;
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};