/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    map<TreeNode*,bool> visited;
public:
    void dfs(TreeNode* root,map<int,int>& mp){
        if(root==NULL || visited[root])   return;
        visited[root] = true;
        mp[root->val]++;
        dfs(root->left,mp);
        dfs(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        dfs(root,mp);
        vector<int> res;
        int maxFreq = INT_MIN;
        for(auto it:mp){
            maxFreq = max(maxFreq,it.second);
        }
        for(auto it:mp){
            if(it.second==maxFreq)  res.push_back(it.first);
        }
        return res;
    }
};
// @lc code=end

