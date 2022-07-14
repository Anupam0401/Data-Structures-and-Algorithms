/*
 * @lc app=leetcode id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* beginHead;
public:
    bool helper(ListNode* head, TreeNode* root, int level){
        if(head==NULL)  return true;
        if(root==nullptr)   return head == NULL?true:false;
        bool val = false;
        if(root->val == head->val){
            val = helper(head->next,root->left,level+1)||helper(head->next,root->right,level+1);
            if(val) return val;
        }
        else val = helper(head,root->left,0) || helper(head,root->right,0);
        if(val == false && level>=1){
            val = helper(beginHead,root->left,0) || helper(beginHead,root->right,0);
        }
        return val;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        beginHead = head;
        return helper(head,root,0);
    }
};
// @lc code=end

