#include <iostream>
using namespace std;

// Implement a Binary Search Tree

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;
    void insert(Node *node, int data)
    {
        if (data < node->data)
        {
            if (node->left == NULL)
            {
                node->left = new Node(data);
            }
            else
            {
                insert(node->left, data);
            }
        }
        else
        {
            if (node->right == NULL)
            {
                node->right = new Node(data);
            }
            else
            {
                insert(node->right, data);
            }
        }
    }
    void deleteNode(Node *node, int data)
    {
        if (node == NULL)
        {
            return;
        }
        if (data < node->data)
        {
            deleteNode(node->left, data);
        }
        else if (data > node->data)
        {
            deleteNode(node->right, data);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                node = NULL;
            }
            else if (node->left == NULL)
            {
                Node *temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == NULL)
            {
                Node *temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                Node *temp = findMin(node->right);
                node->data = temp->data;
                deleteNode(node->right, temp->data);
            }
        }
    }

    Node *findMin(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->left == NULL)
        {
            return node;
        }
        return findMin(node->left);
    }

    void inorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void preorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    bool search(Node *node, int data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        if (data < node->data)
        {
            return search(node->left, data);
        }
        else
        {
            return search(node->right, data);
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    void insert(int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
        }
        else
        {
            insert(root, data);
        }
    }
    void deleteNode(int data)
    {
        deleteNode(root, data);
    }
    void inorder()
    {
        inorder(root);
    }
    void preorder()
    {
        preorder(root);
    }
    void postorder()
    {
        postorder(root);
    }
    bool search(int data)
    {
        return search(root, data);
    }
};

int main(){
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    bst.insert(11);
    bst.insert(13);
    bst.insert(16);
    bst.insert(19);
    bst.insert(2);
    bst.insert(9);
    bst.insert(14);
    bst.insert(17);
    bst.insert(20);
    bst.inorder();
    cout << endl;
    bst.preorder();
    cout << endl;
    bst.postorder();
    cout << endl;
    cout << bst.search(10) << endl;
    cout << bst.search(5) << endl;
    cout << bst.search(15) << endl;
    cout << bst.search(3) << endl;
    cout << bst.search(7) << endl;
    cout << bst.search(12) << endl;
    cout << bst.search(18) << endl;
    cout << bst.search(1) << endl;
    cout << bst.search(4) << endl;
    cout << bst.search(6) << endl;
    cout << bst.search(8) << endl;
    cout << bst.search(11) << endl;
    cout << bst.search(13) << endl;
    cout << bst.search(16) << endl;
    cout << bst.search(19) << endl;
    cout << bst.search(2) << endl;
    cout << bst.search(9) << endl;
    cout << bst.search(14) << endl;
    cout << bst.search(17) << endl;
    cout << bst.search(20) << endl;
    cout << bst.search(21) << endl;
    bst.deleteNode(10);
    bst.inorder();
    cout << endl;
    bst.deleteNode(5);
    bst.inorder();
    cout << endl;
    bst.deleteNode(15);
    bst.inorder();
    cout << endl;
    bst.deleteNode(3);
    bst.inorder();
    cout << endl;
    return 0;
}