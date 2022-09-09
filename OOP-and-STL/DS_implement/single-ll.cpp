#include<iostream>
using namespace std;

// single linked list implementation using C++

struct Node
{
    int key;
    struct Node *next;
}

void insert(struct Node* &root,int n){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = n;
    newNode->next = NULL;
    if(root==NULL){
        root = newNode;
        return;
    }
    struct Node* temp = root;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void print(struct Node* root){
    struct Node* temp = root;
    while(temp){
        cout<<temp->key<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Enter the number of nodes to insert in the linked list: ";
    int n;
    cin>>n;
    struct Node* root = NULL;
    for(int i=0;i<n;i++){
        int newNode;
        cin>>newNode;
        insert(root,newNode);
    }
    printList(root);
}