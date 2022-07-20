/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void insert(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* getNext(char ch){
        return links[ch-'a'];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
                node->insert(word[i],new Node());
            node = node->getNext(word[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node = node->getNext(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if(!node->containsKey(prefix[i]))
                return false;
            node = node->getNext(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

