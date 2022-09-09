#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}queueNode;

typedef struct Queue
{
    queueNode *front;
    queueNode *rear;
}queue;

void init(queue* &q){
    q->front = NULL;
    q->rear = NULL;
}

void insert(queue* &q, int n){
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->data = n;
    newNode->next = NULL;
    if(q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = q->rear->next;
    return;
}

void printQueue(queue* q){
    queueNode* temp = q->front;
    cout<<"\nThe elements in the queue are as follows"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

void dequeue(queue* &q){
    if(q->front==NULL){
        cout<<"Queue is empty!"<<endl;
        return;
    }
    cout<<"\nThe front of the queue is "<<q->front->data<<endl;
    q->front = q->front->next;
    cout<<"Dequeue successfully done!\n"<<endl;
    return;
}

int main(){
    queue* q;
    init(q);
    cout<<"\nEnter the number of nodes to insert: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        insert(q,temp);
    }
    printQueue(q);
    dequeue(q);
    printQueue(q);
    dequeue(q);
    printQueue(q);
    return 0;
}