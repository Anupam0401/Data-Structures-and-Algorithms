#include<stdio.h>
#include <stdlib.h>
#define Max(a,b) (a>b?a:b)

typedef enum COLOUR
{Red, Black}nodeColour;

typedef struct NODE {
  int data;
  struct NODE *right;
  struct NODE *left;
  struct NODE *parent;
  nodeColour colour;
}NODE;

typedef struct RBTree {
  NODE *root;
  NODE *NIL;
}RBTree;

//Declaration of all the functions being used
NODE* new_tree_node(int);
RBTree* new_RBTree();
unsigned int LeafCount(RBTree *,NODE *);
void node_Insert(RBTree *, NODE *);
void RBTree_insertion_fixup(RBTree *, NODE *);
void left_rotate(RBTree *, NODE *);
void right_rotate(RBTree *, NODE *);
NODE* SearchNode(RBTree *,NODE *, int);
void node_deletion(RBTree *,int );
NODE* minimum(RBTree *, NODE *);
void rb_transplant(RBTree *, NODE *, NODE *);
void RBTree_delete_fixup(RBTree *, NODE *);
void inorder(RBTree *, NODE *);
void selectivePrint(NODE*, int, int);
int RBTree_height(RBTree *,NODE *);

NODE* new_tree_node(int data) {
  NODE* n = malloc(sizeof(NODE));
  n->left = NULL;
  n->right = NULL;
  n->parent = NULL;
  n->data = data;
  n->colour = Red;

  return n;
}

RBTree* new_RBTree() {
  RBTree *t = malloc(sizeof(RBTree));
  NODE *nil_node = malloc(sizeof(NODE));
  nil_node->left = NULL;
  nil_node->right = NULL;
  nil_node->parent = NULL;
  nil_node->colour = Black;
  nil_node->data = 0;
  t->NIL = nil_node;
  t->root = t->NIL;
  return t;
}

void selectivePrint(NODE *root, int min, int max)
{
    if (root == NULL)
        return;
    if (min < root->data)
        selectivePrint(root->left, min, max);
    if (min <= root->data && max >= root->data)
        printf("%d  ", root->data);
    if (max > root->data)
        selectivePrint(root->right, min, max);
}

void node_Insert(RBTree *t, NODE *p) {
  NODE* q ,*temp; 
  q=t->NIL;
  temp=t->root;

  while(temp != t->NIL) {
    q = temp;
    if(p->data < temp->data)
      temp = temp->left;
    else
      temp = temp->right;
  }
  p->parent = q;

  if(q == t->NIL) { //newly added node is root
    t->root = p;
  }
  else if(p->data < q->data) //data of child is less than its parent, left child
    q->left = p;
  else
    q->right = p;

  p->right = t->NIL;
  p->left = t->NIL;

  RBTree_insertion_fixup(t, p);
}

void RBTree_insertion_fixup(RBTree *t, NODE *z) {
  while(z->parent->colour == Red) {
    if(z->parent == z->parent->parent->left) { //true if z.parent is the left child of its parent

      NODE *u = z->parent->parent->right; //y denotes the uncle of z

      if(u->colour == Red) { //case 1
        z->parent->colour = Black;
        u->colour = Black;
        z->parent->parent->colour = Red;
        z = z->parent->parent;
      }
      else { //case2 or case3
        if(z == z->parent->right) { //case2
          z = z->parent; //marked z.parent as new z
          left_rotate(t, z);
        }
        //case3
        z->parent->colour = Black; //made parent black
        z->parent->parent->colour = Red; //made parent red
        right_rotate(t, z->parent->parent);
      }
    }
    else { //z.parent is the right child
      NODE *u = z->parent->parent->left; //uncle of z

      if(u->colour == Red) {
        z->parent->colour = Black;
        u->colour = Black;
        z->parent->parent->colour = Red;
        z = z->parent->parent;
      }
      else {
        if(z == z->parent->left) {
          z = z->parent; //marked z.parent as new z
          right_rotate(t, z);
        }
        z->parent->colour = Black; //made parent black
        z->parent->parent->colour = Red; //made parent red
        left_rotate(t, z->parent->parent);
      }
    }
  }
  t->root->colour = Black;
}

void left_rotate(RBTree *t, NODE *x) {
  NODE *y = x->right;
  x->right = y->left;
  if(y->left != t->NIL) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if(x->parent == t->NIL) { //x is root
    t->root = y;
  }
  else if(x == x->parent->left) { //x is left child
    x->parent->left = y;
  }
  else { //x is right child
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

void right_rotate(RBTree *t, NODE *x) {
  NODE *y = x->left;
  x->left = y->right;
  if(y->right != t->NIL) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if(x->parent == t->NIL) { //x is root
    t->root = y;
  }
  else if(x == x->parent->right) { //x is left child
    x->parent->right = y;
  }
  else { //x is right child
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}

unsigned int LeafCount(RBTree *t,NODE *node)
{
    if (node == t->NIL)
        return 0;
    if (node->left == t->NIL && node->right == t->NIL)
        return 1;
    else
        return LeafCount(t,node->left) + LeafCount(t,node->right);
}

void rb_transplant(RBTree *t, NODE *u, NODE *v) {
  if(u->parent == t->NIL)
    t->root = v;
  else if(u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  v->parent = u->parent;
}

NODE* minimum(RBTree *t, NODE *x) {
  while(x->left != t->NIL)
    x = x->left;
  return x;
}

NODE* SearchNode(RBTree *t,NODE *node, int x)
{
    if(node==t->NIL)
    {
        printf("\nNumber to be deleted was not found\n Deletion unsuccessful\n");
        return node;
    }
    if(x>node->data)
        SearchNode(t,node->right,x);
    else if(x<node->data)
        SearchNode(t,node->left,x);
    else
        {
            printf("\nDeletion succesful\n");
            return node;
        }
}

void node_deletion(RBTree *t,int d) 
{
  NODE *z=SearchNode(t,t->root,d);
  if(z==t->NIL) return;
  NODE *y = z;
  NODE *x;
  enum COLOUR y_orignal_colour = y->colour;
  if(z->left == t->NIL) {
    x = z->right;
    rb_transplant(t, z, z->right);
  }
  else if(z->right == t->NIL) {
    x = z->left;
    rb_transplant(t, z, z->left);
  }
  else {
    y = minimum(t, z->right);
    y_orignal_colour = y->colour;
    x = y->right;
    if(y->parent == z) {
      x->parent = z;
    }
    else {
      rb_transplant(t, y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    rb_transplant(t, z, y);
    y->left = z->left;
    y->left->parent = y;
    y->colour = z->colour;
  }
  if(y_orignal_colour == Black)
    RBTree_delete_fixup(t, x);
}
void RBTree_delete_fixup(RBTree *t, NODE *x) {
  while(x != t->root && x->colour == Black) {
    if(x == x->parent->left) {
      NODE *w = x->parent->right;
      if(w->colour == Red) {
        w->colour = Black;
        x->parent->colour = Red;
        left_rotate(t, x->parent);
        w = x->parent->right;
      }
      if(w->left->colour == Black && w->right->colour == Black) {
        w->colour = Red;
        x = x->parent;
      }
      else {
        if(w->right->colour == Black) {
          w->left->colour = Black;
          w->colour = Red;
          right_rotate(t, w);
          w = x->parent->right;
        }
        w->colour = x->parent->colour;
        x->parent->colour = Black;
        w->right->colour = Black;
        left_rotate(t, x->parent);
        x = t->root;
      }
    }
    else {
      NODE *w = x->parent->left;
      if(w->colour == Red) {
        w->colour = Black;
        x->parent->colour = Red;
        right_rotate(t, x->parent);
        w = x->parent->left;
      }
      if(w->right->colour == Black && w->left->colour == Black) {
        w->colour = Red;
        x = x->parent;
      }
      else {
        if(w->left->colour == Black) {
          w->right->colour = Black;
          w->colour = Red;
          left_rotate(t, w);
          w = x->parent->left;
        }
        w->colour = x->parent->colour;
        x->parent->colour = Black;
        w->left->colour = Black;
        right_rotate(t, x->parent);
        x = t->root;
      }
    }
  }
  x->colour = Black;
}


void inorder(RBTree *t, NODE *n) {
  if(n != t->NIL) {
    inorder(t, n->left);
    printf("%d   ", n->data);
    if(n->colour) printf("BLACK  ");
    else  printf("RED  ");
    printf("%p  %p  %p\n",&n->parent,&n->left,&n->right);
    inorder(t, n->right);
  }
}

int RBTree_height(RBTree *t,NODE *node){
    if(node==t->NIL)
        return 0;
    else
        return (Max(RBTree_height(t,node->left),RBTree_height(t,node->right)))+1;
}

int main() {
  RBTree *t = new_RBTree();
    int no_of_nodes,n,d,min,max,f;
    printf("Enter the total number of the nodes you want to insert in the RBTree\n");
    scanf("%d", &no_of_nodes);
    printf("Enter the data  \n");
    for (int i = 1; i <= no_of_nodes; i++){
        NODE *a;
        scanf("%d",&n);
        a=new_tree_node(n);
        node_Insert(t,a);
    }
    printf("\nThe tree formed is shown below\n");
    inorder(t, t->root);
    printf("\nThe leaf count is %d",(LeafCount(t,t->root)));
    printf("\nEnter the number of times you want to perform deletion\n");
    scanf("%d",&no_of_nodes);
    for(int i=1;i<=no_of_nodes;i++)
    {
    printf("\nEnter a number to delete\n");
    scanf("%d",&d);
    node_deletion(t,d);
    printf("\nThe tree formed is shown below\n");
    inorder(t,t->root);
    }
    printf("\nEnter the numbers between which the nodes are to be printed\n");
    scanf("%d%d",&min,&max);
    selectivePrint(t->root,min,max);
    //if(f==0) printf("\nNo numbers found between the given intervals inclusive\n");
    /*printf("1.Insert nodes in the RED BLACK Tree\n");
    printf("2.Delete a node from the tree\n");
    printf("3.Check")*/
    printf("\nThe height of the red black tree is %d",RBTree_height(t,t->root));
    return 0;
}