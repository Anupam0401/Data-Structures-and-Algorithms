#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int front, back;
    int *data;
}NODE;

void enqueue(NODE **root_ref,int n){
    
}

int main(){
    NODE *queue =(NODE*)malloc(sizeof(NODE));
    queue->front = queue->back =-1;
    cout<<"Enter the nnumber of nodes you want to insert in the queue: ";
    int n,t;
    cin>>n;
    cout<<"\nEnter the nodes\n";
    for(int i=0; i<n; i++){
        cin>>t;
        enqueue(&queue,n);
    }
}