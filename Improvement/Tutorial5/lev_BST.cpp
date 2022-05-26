// C++ implementation to construct a BST
// from its level order traversal
#include <bits/stdc++.h>

using namespace std;


// node of a BST
struct Node
{
	int data;
	Node *left, *right;
};


// function to get a new node
Node* insertNode(int data)
{
	// Allocate memory
	Node *newNode =
		(Node*)malloc(sizeof(Node));
	
	// put in the data	
	newNode->data = data;
	newNode->left = newNode->right = NULL;	
	return newNode;
}


// function to construct a BST from
// its level order traversal
Node *LevelOrder(Node *root , int data)
{
	if(root==NULL){	
		root = insertNode(data);
		return root;
	}
	if(data <= root->data)
	root->left = LevelOrder(root->left, data);
	else
	root->right = LevelOrder(root->right, data);
	return root;	
}

Node* constructBst(int arr[], int n)
{
	if(n==0)return NULL;
	Node *root =NULL;

	for(int i=0;i<n;i++)
	root = LevelOrder(root , arr[i]);
	
	return root;
}

// function to print the inorder traversal
void inorderTraversal(Node* root,int n)
{
    int a[n];
	if (!root)
		return;
	int i=0;
	inorderTraversal(root->left,n);
	cout << root->data << " ";
    a[i++] = root->data;
	inorderTraversal(root->right,n);	
    cout<<"\n\n";
    for(int j = 0; j < n-1; j++)
    {
        if(a[j]>a[j+1]){
            cout<<"NOT A BST!"<<endl;
            return;
        }
    }
    cout<<"Perfect BST!"<<endl;
}

// Driver program to test above
int main()
{
    cout<<"Enter the number of elements"<<endl;
    int n;
    cin>>n;
	int arr[n] ={0};
    cout<<"\nEnter the elements in level order"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
	Node *root = constructBst(arr, n);
	cout << "Inorder Traversal: ";
	inorderTraversal(root,n);
	return 0;	
}
