/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* current,unordered_map<Node*,Node*>& m){
        vector<Node*> neighbour;
        Node* clone = new Node()
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)   return NULL;
        if(node->neighbours == NULL){
            return new Node(node->val);
        }
        unordered_map<Node*, Node*> m;
        return dfs(node,m);
    }
};
// @lc code=end

