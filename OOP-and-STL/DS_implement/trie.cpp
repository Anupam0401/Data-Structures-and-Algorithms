#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    // check if refernce trie is present or not
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    // put the node in the link
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // set the end of the word
    void setEnd()
    {
        flag = true;
    }

    // check the end of the word
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());

            // move to the reference
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }

    // misc
//     Then, we are going to generate all substrings of the given string. It can be done by 2 nested loops. For each iteration, the outer loop fixes the starting point and the inner loop traverses the substring from the starting point to the end of the string.
// For each character encountered in the traversal of the inner loop, we are checking whether that particular node in the trie already contains the character or not. 
// If it has, it means that the currently generated substring is a duplicate one. And we can just go to the next iteration to check the next character. But if the current character is not in the current node, then it means that the current substring generated is a brand new one.
    int countDistinctSubstrings(string &s)
    {
        Node *root = new Node();
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = root;

            for (int j = i; j < n; j++)
            {
                if (!node->containsKey(s[j]))
                {
                    node->put(s[j], new Node());
                    count++;
                }
                node = node->get(s[j]);
            }
        }
        return count + 1;
    }
};

int main()
{
    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            trie.insert(value[i]);
        }
        else if (type[i] == 2)
        {
            if (trie.search(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
        else
        {
            if (trie.startsWith(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
    }
}