//Done by Anupam Kumar
//11940160
//Part B

#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

typedef struct node { //tree node
  int weight;
  struct node *left, *right;
}NODE;

int max_weight = 0;
// Create a node
NODE *newNode(int item) {
  NODE *temp = (NODE *)malloc(sizeof(NODE));
  temp->weight = item;
  temp->left = temp->right = NULL;
  return temp;
}

void findMaxWeigthPath(int ints[], int len);
void max_weightPath(NODE* node);
void getPath_Recursive(NODE* node, int path[], int pathLen);
NODE *insert(NODE *node, int weight);

// Insert a node
NODE *insert(NODE *node, int weight) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(weight);

  // Traverse to the right place and insert the node
  if (weight < node->weight)
    node->left = insert(node->left, weight);
  else
    node->right = insert(node->right, weight);

  return node;
}


// Recursive Function gives a node and the path array 
void getPath_Recursive(NODE* node, int path[], int pathLen) 
{
  if (node==NULL) 
    return;
  
  /* append this node to the path array */
  path[pathLen] = node->weight;
  pathLen++;
  
  /* it's a leaf, so print the path that led to here  */
  if (node->left==NULL && node->right==NULL) 
  {
    findMaxWeigthPath(path, pathLen);
  }
  else 
  {
    /* otherwise try both subtrees */
    getPath_Recursive(node->left, path, pathLen);//left sub tree recursive call
    getPath_Recursive(node->right, path, pathLen);//right sub tree recursive call
  }
}

void findMaxWeigthPath(int ints[], int len) //finds the maximum path after each execution
{
    int sum=0;
  for (int i=0; i<len; i++) 
  {
    sum+=ints[i];//sum of node weights
  }
  if(sum>max_weight) max_weight=sum;//max path till then
}   

void max_weightPath(NODE* node) 
{
  int path[MAX]; //stores the path
  getPath_Recursive(node, path, 0);//call the function to find the paths recursively
}

// Driver code
int main() {
  NODE *root = NULL;
  int n;
  cout<<"Enter the number of nodes you want to create in the tree: ";
  cin>>n;
  cout<<"\n\nEnter the "<<n<<" nodes of the tree\n"<<endl;
  int p;
  //We are making a binary search tree using the data entered by the user.
  for(int i=0; i<n; i++)
  {
      cin>>p;
      root = insert(root, p); //inserting the node in the tree
  }
    max_weightPath(root);
    cout<<"MAXIMUM weighted path value = "<<max_weight<<endl;
}
