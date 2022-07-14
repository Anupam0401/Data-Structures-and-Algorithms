#include<stdio.h>
#include <stdlib.h>

enum COLOR {Red, Black};

typedef struct NODE {
  int data;
  struct NODE *right;
  struct NODE *left;
  struct NODE *parent;
  enum COLOR color;
}NODE;

typedef struct RBTree {
  NODE *root;
  NODE *NIL;
}RBTree;

//Declaration of all the functions being used
NODE* new_tree_node(int);
RBTree* new_RBTree();
void left_rotate(RBTree *, NODE *);
void right_rotate(RBTree *, NODE *);
void insertion_fixup(RBTree *, NODE *);
void insert(RBTree *, NODE *);
void inorder(RBTree *, NODE *);
unsigned int LeafCount(NODE*);
void selectivePrint(NODE*, int, int);

NODE* new_tree_node(int data) {
  NODE* n = malloc(sizeof(NODE));
  n->left = NULL;
  n->right = NULL;
  n->parent = NULL;
  n->data = data;
  n->color = Red;

  return n;
}

RBTree* new_RBTree() {
  RBTree *t = malloc(sizeof(RBTree));
  NODE *nil_node = malloc(sizeof(NODE));
  nil_node->left = NULL;
  nil_node->right = NULL;
  nil_node->parent = NULL;
  nil_node->color = Black;
  nil_node->data = 0;
  t->NIL = nil_node;
  t->root = t->NIL;

  return t;
}
unsigned int LeafCount(NODE *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return LeafCount(node->left) + LeafCount(node->right);
}

void selectivePrint(NODE *root, int min, int max)
{
    if (root == NULL)
    {
        return;
    }
    if (min < root->data)
        selectivePrint(root->left, min, max);
    if (min <= root->data && max >= root->data)
        printf("%d  ", root->data);
    if (max > root->data)
        selectivePrint(root->right, min, max);
}

void insert(RBTree *t, NODE *p) {
  NODE* q = t->NIL; //variable for the parent of the added node
  NODE* temp = t->root;

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

  insertion_fixup(t, p);
}

void insertion_fixup(RBTree *t, NODE *z) {
  while(z->parent->color == Red) {
    if(z->parent == z->parent->parent->left) { //z.parent is the left child

      NODE *y = z->parent->parent->right; //uncle of z

      if(y->color == Red) { //case 1
        z->parent->color = Black;
        y->color = Black;
        z->parent->parent->color = Red;
        z = z->parent->parent;
      }
      else { //case2 or case3
        if(z == z->parent->right) { //case2
          z = z->parent; //marked z.parent as new z
          left_rotate(t, z);
        }
        //case3
        z->parent->color = Black; //made parent black
        z->parent->parent->color = Red; //made parent red
        right_rotate(t, z->parent->parent);
      }
    }
    else { //z.parent is the right child
      NODE *y = z->parent->parent->left; //uncle of z

      if(y->color == Red) {
        z->parent->color = Black;
        y->color = Black;
        z->parent->parent->color = Red;
        z = z->parent->parent;
      }
      else {
        if(z == z->parent->left) {
          z = z->parent; //marked z.parent as new z
          right_rotate(t, z);
        }
        z->parent->color = Black; //made parent black
        z->parent->parent->color = Red; //made parent red
        left_rotate(t, z->parent->parent);
      }
    }
  }
  t->root->color = Black;
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

/*void rb_transplant(RBTree *t, NODE *u, NODE *v) {
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

void rb_delete_fixup(RBTree *t, NODE *x) {
  while(x != t->root && x->color == Black) {
    if(x == x->parent->left) {
      NODE *w = x->parent->right;
      if(w->color == Red) {
        w->color = Black;
        x->parent->color = Red;
        left_rotate(t, x->parent);
        w = x->parent->right;
      }
      if(w->left->color == Black && w->right->color == Black) {
        w->color = Red;
        x = x->parent;
      }
      else {
        if(w->right->color == Black) {
          w->left->color = Black;
          w->color = Red;
          right_rotate(t, w);
          w = x->parent->right;
        }
        w->color = x->parent->color;
        x->parent->color = Black;
        w->right->color = Black;
        left_rotate(t, x->parent);
        x = t->root;
      }
    }
    else {
      NODE *w = x->parent->left;
      if(w->color == Red) {
        w->color = Black;
        x->parent->color = Red;
        right_rotate(t, x->parent);
        w = x->parent->left;
      }
      if(w->right->color == Black && w->left->color == Black) {
        w->color = Red;
        x = x->parent;
      }
      else {
        if(w->left->color == Black) {
          w->right->color = Black;
          w->color = Red;
          left_rotate(t, w);
          w = x->parent->left;
        }
        w->color = x->parent->color;
        x->parent->color = Black;
        w->left->color = Black;
        right_rotate(t, x->parent);
        x = t->root;
      }
    }
  }
  x->color = Black;
}

void rb_delete(RBTree *t, NODE *z) {
  NODE *y = z;
  NODE *x;
  enum COLOR y_orignal_color = y->color;
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
    y_orignal_color = y->color;
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
    y->color = z->color;
  }
  if(y_orignal_color == Black)
    rb_delete_fixup(t, x);
}*/

void inorder(RBTree *t, NODE *n) {
  if(n != t->NIL) {
    inorder(t, n->left);
    printf("%d\n", n->data);
    inorder(t, n->right);
  }
}

int main() {
  RBTree *t = new_RBTree();
    int no_of_nodes,n;
    printf("\nEnter the number of the nodes you want to insert\n");
    scanf("%d", &no_of_nodes);
    for (int i = 1; i <= no_of_nodes; i++){
        NODE *a;
        printf("Enter the data");
        scanf("%d",&n);
        a=new_tree_node(n);
        insert(t,a);
    }
    inorder(t, t->root);
    selectivePrint(t->root,10,13);
    //printf("The leaf count is %d",(LeafCount(t->root)));
  return 0;
}