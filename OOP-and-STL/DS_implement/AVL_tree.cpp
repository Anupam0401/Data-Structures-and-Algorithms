#include <iostream>
using namespace std;

// implement AVL trees
// AVL trees are self balancing trees
// AVL trees are height balanced trees
// AVL trees are binary search trees
// AVL trees are binary trees
// AVL trees are trees

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }

    // height of the tree
    int heightOfTree(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return root->height;
    }

    // balance factor of the tree
    int balanceFactor(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return heightOfTree(root->left) - heightOfTree(root->right);
    }

    // left rotation
    Node *leftRotation(Node *root)
    {
        Node *newRoot = root->right;
        Node *temp = newRoot->left;
        newRoot->left = root;
        root->right = temp;
        root->height = max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
        newRoot->height = max(heightOfTree(newRoot->left), heightOfTree(newRoot->right)) + 1;
        return newRoot;
    }

    // right rotation
    Node *rightRotation(Node *root)
    {
        Node *newRoot = root->left;
        Node *temp = newRoot->right;
        newRoot->right = root;
        root->left = temp;
        root->height = max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
        newRoot->height = max(heightOfTree(newRoot->left), heightOfTree(newRoot->right)) + 1;
        return newRoot;
    }

    // insert a node in the tree
    Node *insertNode(Node *root, int d)
    {
        if (root == NULL)
        {
            return new Node(d);
        }
        if (d < root->data)
        {
            root->left = insertNode(root->left, d);
        }
        else
        {
            root->right = insertNode(root->right, d);
        }
        root->height = max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
        int balance = balanceFactor(root);
        // left left case
        if (balance > 1 && d < root->left->data)
        {
            return rightRotation(root);
        }
        // right right case
        if (balance < -1 && d > root->right->data)
        {
            return leftRotation(root);
        }
        // left right case
        if (balance > 1 && d > root->left->data)
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
        // right left case
        if (balance < -1 && d < root->right->data)
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
        return root;
    }

    // print the tree
    void printTree(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }

    // delete a node from the tree
    Node *deleteNode(Node *root, int d)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (d < root->data)
        {
            root->left = deleteNode(root->left, d);
        }
        else if (d > root->data)
        {
            root->right = deleteNode(root->right, d);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
        root->height = max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
        int balance = balanceFactor(root);
        // left left case
        if (balance > 1 && balanceFactor(root->left) >= 0)
        {
            return rightRotation(root);
        }
        // right right case
        if (balance < -1 && balanceFactor(root->right) <= 0)
        {
            return leftRotation(root);
        }
        // left right case
        if (balance > 1 && balanceFactor(root->left) < 0)
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
        // right left case
        if (balance < -1 && balanceFactor(root->right) > 0)
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
        return root;
    }

    // search a node in the tree
    bool searchNode(Node *root, int d)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == d)
        {
            return true;
        }
        if (d < root->data)
        {
            return searchNode(root->left, d);
        }
        else
        {
            return searchNode(root->right, d);
        }
    }

    // find the minimum element in the tree
    int findMin(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->left == NULL)
        {
            return root->data;
        }
        return findMin(root->left);
    }

    // find the maximum element in the tree
    int findMax(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->right == NULL)
        {
            return root->data;
        }
        return findMax(root->right);
    }


};


int main()
{
    AVLTree tree;
    tree.root = tree.insertNode(tree.root, 10);
    tree.root = tree.insertNode(tree.root, 20);
    tree.root = tree.insertNode(tree.root, 30);
    tree.root = tree.insertNode(tree.root, 40);
    tree.root = tree.insertNode(tree.root, 50);
    tree.root = tree.insertNode(tree.root, 25);
    tree.printTree(tree.root);
    cout << endl;
    tree.root = tree.deleteNode(tree.root, 20);
    tree.printTree(tree.root);
    cout << endl;
    cout << tree.searchNode(tree.root, 30) << endl;
    cout << tree.findMin(tree.root) << endl;
    cout << tree.findMax(tree.root) << endl;
    return 0;
}