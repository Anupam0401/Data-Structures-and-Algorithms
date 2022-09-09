#include<iostream>
using namespace std;

// single linked list implementation using C++

struct Node
{
    int key;
    struct Node *next;
};

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

void printList(struct Node* root){
    struct Node* temp = root;
    cout<<"The linked list formed so far is: ";
    while(temp){
        cout<<temp->key<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNode(struct Node* &root, int n){
    struct Node* temp = root;
    if(temp->key == n){
        root = temp->next;
        return;
    }
    while(temp->next!=NULL){
        if(temp->next->key==n){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

int main(){
    cout<<"Enter the number of nodes to insert in the linked list: ";
    int n;
    cin>>n;
    struct Node* root = NULL;
    cout<<"\nEnter the nodes"<<endl;
    for(int i=0;i<n;i++){
        int newNode;
        cin>>newNode;
        insert(root,newNode);
    }
    printList(root);
    cout<<"\n\nEnter the value of the node to be deleted: ";
    int del;
    cin>>del;
    deleteNode(root,del);
    printList(root);
}