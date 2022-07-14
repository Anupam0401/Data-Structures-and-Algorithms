#include <bits/stdc++.h>
using namespace std;
 
 
class stackNode { 
  public:
    int data;
    stackNode *next;
    stackNode(int a) { 
        data = a;
        next = NULL;
    }
};
 
stackNode *top=NULL; 
int size=0;
 
 
void push(int x) { 
 
    stackNode* node=(stackNode*)(malloc(sizeof(stackNode)));
    node->data=x;
    node->next=top;
    top=node;
    cout<<x<<" is pushed\n";
    size++;
}
 
bool isEmpty(){
  if(top==NULL && size==0)
  return true;
  else
  return false;
}
 
int pop() { 
 
    if(isEmpty()){
      cout<<"stack is empty\n";
      return INT_MIN;
    }
    else{
        size--;
        int temp=top->data;
        stackNode* tempNode=top;
        top=top->next;
        free(tempNode);
        return temp;
    }
}
 
int top_stack(){ 
  if(isEmpty()){
    cout<<"stack is empty\n";
    return INT_MIN;
  }
  else{
    return top->data;
  }
 
}
 
int main(){
      int data;
      cout<<"Enter string\n";
      cin>>data;
      push(data);
    }
  return 0;
}