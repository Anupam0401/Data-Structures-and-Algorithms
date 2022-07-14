// C++ program to construct a Binary Tree from parent array
#include<bits/stdc++.h>
using namespace std;

// A tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Utility function to create new Node
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}


int Randoms(int lower, int upper, int count)
{
    for (int i = 0; i < count; i++) {
        int num = (rand() %(upper - lower + 1)) + lower;
        return num;
    }
}



// Creates a node with key as 'i'. If i is root, then it changes
// root. If parent of i is not created, then it creates parent first
void createNode(int parent[], int i, Node *created[], Node **root)
{    int x = Randoms(1,3,3);
	// node is already created
	if (created[i] != NULL)
		return;

	// Create a new node and set created[i]
	created[i] = newNode(i);

	// If 'i' is root, change root pointer and return
	if (parent[i] == -1)
	{
		*root = created[i];
		return;
	}

	// If parent is not created, then create parent first
	if (created[parent[i]] == NULL)
		createNode(parent, parent[i], created, root);

	// Find parent pointer
	Node *p = created[parent[i]];

    if(x==1)
    p->left = created[i];
    else if(x==2)
    p->right = created[i];
    else 
    {   if(p->left == NULL)
		    p->left = created[i];
	    else // If second child
		    p->right = created[i];
    }
	
}

// Creates tree from parent[0..n-1] and returns root of the created tree
Node *createTree(int parent[], int n)
{
	// Create an array created[] to keep track
	// of created nodes, initialize all entries
	// as NULL
	Node *created[n];
	for (int i=0; i<n; i++)
		created[i] = NULL;

	Node *root = NULL;
	for (int i=0; i<n; i++)
		createNode(parent, i, created, &root);

	return root;
}

//For adding new line in a program
inline void newLine(){
	cout << "\n";
}

// Utility function to do inorder traversal
void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}




// Driver method
int main()
{
	int parent[] = {-1, 0, 0, 1, 1, 3, 5};
	int n = sizeof parent / sizeof parent[0];
	Node *root = createTree(parent, n);
	cout << "Inorder Traversal of constructed tree\n";
	inorder(root);
	newLine();
}