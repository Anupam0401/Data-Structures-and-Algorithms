/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> res;
        if(root==NULL)  return res;
        TreeNode* curr = root;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({curr,{0,0}});
        while(!q.empty()){
            TreeNode* front = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            mp[x][y].insert(front->val);
            if(front->left) q.push({front->left,{x-1,y+1}});
            if(front->right) q.push({front->right,{x+1,y+1}});
        }
        for(auto it:mp){
            vector<int> temp;
            for(auto ele:it.second){
                for(auto x: ele.second){
                    temp.push_back(x);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

