#include <bits/stdc++.h>
using namespace std ; 

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = ;  


class node
{
public:
  
  node* child[2];
  node()
  {
    this->child[0]=NULL;
    this->child[1]=NULL;
  }
};

int n, q ;
node* trieArr[4*N] ;
int a[N] ;

void combine(node* &root, node* root1, node* root2) {
  
  if(root1 == NULL && root2 == NULL)
    return ;
  root = new node();
  if(root1 == NULL) {
    root = root2;
    return ;
  }
  if(root2 == NULL) {
    root = root1 ;
    return ;
  }

  combine(root->child[0],root1->child[0],root2->child[0]) ;
  combine(root->child[1], root1->child[1], root2->child[1]) ;

}


void insertInTrie(node *root, int x) {
  node *cur = root ;
  for(int i = 31 ; i >= 0 ; --i) {
    int b= (x >> i) & 1;
    if(b== 0) {
      if(!cur->child[0]) 
        cur->child[0] = new node() ;
      cur = cur->child[0];
    } else {
      if(!cur->child[1])
        cur->child[1] = new node() ;
      cur = cur->child[1] ;
    }
  }
}


int queryinTrie(node *root, int x) {
  int mxVal =0; 
  node *cur = root ; 
  for(int i = 31;  i>= 0 ; --i) {
    int b = (x >> i) & 1;
    if(b == 1) {
      if(cur->child[0]) {
        mxVal+= (1<<i) ;
        cur = cur->child[0] ;
      }
      else {
        cur=cur->child[1] ;

      }
    } else {
      if(cur->child[1]) {
        mxVal += (1<<i) ;
        cur = cur -> child[1] ;
      } else {
        cur = cur -> child[0] ;
      }
    } 
  }
  return mxVal ;
}

void build(int v, int low, int high) {
  if(low > high)
    return ;
  if(low == high) {
    trieArr[v] = new node() ;
    insertInTrie(trieArr[v], a[low]) ;
    return ;
  }
  int mid=(low + high)/2; 
  build(v*2, low, mid);
  build(v*2+1, mid+1, high) ;
  combine(trieArr[v], trieArr[v*2], trieArr[v*2+1]) ;
}

int query(int v, int low, int high, int ql, int qr, int val) {

  if(ql > high || low > qr) 
    return 0 ;
  if(low >= ql && high <= qr) {
    return queryinTrie(trieArr[v], val) ;
  }
  int mid = (low + high) / 2;

  return max( query(v*2,low,mid, ql, qr, val) , 
    query(v*2+1, mid+1,high, ql, qr,val) ) ;
}

int32_t main() {
  IOS ; 

  cin >> n  ; 

  for(int i = 0 ; i < n ; ++i)
    cin >> a[i] ; 

  build(1,0,n-1) ;

  cin >> q ; 

  while(q--) {
    int l, r , x; 
    cin >> l >> r >> x ;  
    cout << query(1,0,n-1, l-1,r-1,x) << "\n" ;
  }
  
  return 0 ;
}