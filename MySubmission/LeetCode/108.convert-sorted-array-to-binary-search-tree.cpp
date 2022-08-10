/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* dfs(vector<int>& nums,int l, int r)
    {
        if(l>r) return NULL;
        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums,l,mid-1);
        root->right = dfs(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n  = nums.size();
        if(n==0)    return NULL;
        return dfs(nums, 0, n-1);
        // TreeNode* root = new TreeNode(nums[mid]);
        // TreeNode* leftst = root;
        // TreeNode* rightst = root;
        // int l = mid-1,r = mid+1;
        // while(l>=0 || r<n){
        //     if(l>=0){
        //         leftst->left = new TreeNode(nums[l--]);
        //         leftst = leftst->left;
        //     }
        //     if(r<n){
        //         rightst->right = new TreeNode(nums[r++]);
        //         rightst = rightst->right;
        //     }
        // }
        // return root;
    }
};
// @lc code=end

