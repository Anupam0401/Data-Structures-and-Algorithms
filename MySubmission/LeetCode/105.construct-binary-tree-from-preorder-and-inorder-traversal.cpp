/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    // TreeNode* makeTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd)
    // {
    //     if(preStart>preEnd || inStart>inEnd)
    //         return nullptr;
    //     int rootVal = preorder[preStart];
    //     TreeNode* root = new TreeNode(rootVal);
    //     int rootIndex = find(inorder.begin()+inStart, inorder.begin()+inEnd, rootVal) - inorder.begin();
    //     int leftLen = rootIndex - inStart;
    //     root->left = makeTree(preorder, preStart+1, preStart+leftLen, inorder, inStart, rootIndex-1);
    //     root->right = makeTree(preorder, preStart+leftLen+1, preEnd, inorder, rootIndex+1, inEnd);
    //     return root;
    // }
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     int preLen = preorder.size();
    //     int inLen = inorder.size();
    //     if(preLen != inLen)
    //         return NULL;
    //     if(preLen == 0)
    //         return NULL;
    //     return makeTree(preorder, 0, preLen-1, inorder, 0, inLen-1);
    // }

    // done using map, TC reduced to O(n)
    TreeNode* makeTree(int preStart,int preEnd, vector<int>& preorder, int inStart, int inEnd, vector<int>& inorder,unordered_map<int,int>& in_mp){
        if(preStart>preEnd || inStart>inEnd)    return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int in_index = in_mp[preorder[preStart]];
        int left_size = in_index - inStart;
        root->left = makeTree(preStart+1,preStart+left_size,preorder,inStart,in_index-1,inorder,in_mp);
        root->right = makeTree(preStart+left_size+1,preEnd,preorder,in_index+1,inEnd,inorder,in_mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n = inorder.size();
        unordered_map<int,int> in_mp;
        for(int i=0;i<n;i++)    in_mp[inorder[i]]=i;
        return makeTree(0,n-1,preorder,0,n-1,inorder,in_mp);
    }
};
// @lc code=end

