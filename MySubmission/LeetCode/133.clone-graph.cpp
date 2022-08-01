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
        Node* clone = new Node(current->val);
        m[current] = clone;
        for(auto it:current->neighbors){
            if(m.find(it)!=m.end())
                neighbour.push_back(m[it]);
            else
                neighbour.push_back(dfs(it,m));
        }
        clone->neighbors = neighbour;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)   return NULL;
        if(node->neighbors.size()==0)
            return new Node(node->val);
        unordered_map<Node*, Node*> m;
        return dfs(node,m);
    }
};
// @lc code=end

