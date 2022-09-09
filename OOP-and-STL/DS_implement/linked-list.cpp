#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *next;
};

void insertSorted(int n, struct Node **root)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = n;
    newNode->next = NULL;
    if (*root == NULL) //new root
    {
        *root = newNode;
        return;
    }
    struct Node *temp = *root, *x;
    if (n < temp->key) //insertion at the very beginning
    {
        newNode->next = temp;
        *root = newNode;
        return;
    }
    x = *root;
    while (x != NULL)
    {
        if (x->next == NULL)
        {
            x->next = newNode;
            return;
        }
        if (n >= x->key && n < x->next->key)
            break;
        x = x->next;
    }
    newNode->next = x->next;
    x->next = newNode;
    return;
}

void print(struct Node *root)
{
    while (root->next != NULL)
    {
        cout << root->key << "-->";
        root = root->next;
    }
    cout << root->key << "\n";
}

void delete_node(struct Node **root, int n)
{
    struct Node *current = *root, *prev;
    // cout<<current->next->key<<"\n";
    // *root=current->next;
    if (current->key == n)
    {
        *root = current->next;
        return;
    }
    prev = current;
    while (current != NULL)
    {
        if (current->key == n)
        {
            prev->next = current->next;
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main()
{
    struct Node *root = NULL;
    cout << "Enter the number of nodes you would like to insert: ";
    int n = 0;
    cin >> n;
    cout << "Enter the nodes:\n";
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        insertSorted(t, &root);
    }
    print(root);
    int x = 1;
    cout << "\nEnter the node to delete: ";
    cin >> x;
    delete_node(&root, x);
    print(root);
}