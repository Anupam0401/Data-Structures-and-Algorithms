#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> val;
std::vector<int>::iterator c = val.begin();




struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

/* Helper function that allocates a new
   node with the given key and NULL left
   and right pointers.*/
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->key);
    printInorder(node->right);
}
void store(struct Node* root)
{
    if(root==NULL)
    return;
    val.push_back(root->key);
    store(root->left);
    store(root->right);

}
void arrange()
{
    sort(val.begin(),val.end());
}
void replace(struct Node* node)
{
    if(node==NULL)
    return;
    replace(node->left);
    node->key=*c;
    if(c+1<val.end())
    c++;
    else
    return;
    if(node->right)
    replace(node->right);
    return;
}


int main()
{
    /* Create following BST
            9
            / \
        6     15 */
    Node* root = newNode(4);
    root->left = newNode(15);
    root->right = newNode(6);
        root->left->left = newNode(9);
                root->left->right = newNode(8);
                root->right->left = newNode(17);
                root->right->right = newNode(13);



    printf(" Original BST\n");
    printInorder(root);
    store(root);
    arrange();
    replace(root);


    printf("\n BST To Binary Tree\n");
    printInorder(root);

    return 0;
}
