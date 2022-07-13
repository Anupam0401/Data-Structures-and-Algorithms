/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = 0;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                v.push_back(t->val);
                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }
            // insert reversely
            if (flag)
            {
                reverse(v.begin(), v.end());
                res.push_back(v);
            }
            else
                res.push_back(v);
            flag = !flag;
        }
        return res;
    }
};
// @lc code=end
