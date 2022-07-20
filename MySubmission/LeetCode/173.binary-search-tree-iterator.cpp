/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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

// Approach: 
// used a stack for storing the inorder traversal
// The inorder traversal is stored upto a maximum of O(H) because we pop out the elements as soon as next is called and push the right side of that node
// hasNext() can simply be found out by checking the emptiness of the stack

// TC - O(n/n) (average)
// SC - O(H) for storing the nodes in the stack
class BSTIterator {
private:
    stack<TreeNode*> stk;
    void pushAll(TreeNode* root){
        while(root!=NULL){
            stk.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        if(stk.empty()) return -1;
        TreeNode *temp = stk.top();
        stk.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(!stk.empty())    return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

