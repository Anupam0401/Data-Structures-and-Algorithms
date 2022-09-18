#include<iostream>
using namespace std;

// implement stacks using queue
typedef struct Node
{
    int data;
    Node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if(q->front == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if(q->front == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    else
    {
        Node *temp = q->front;
        int data = temp->data;
        q->front = q->front->next;
        delete temp;
        return data;
    }
}

void push(Queue *q, int data)
{
    enqueue(q, data);
}

int pop(Queue *q)
{
    Queue temp;
    initQueue(&temp);
    int data;
    while(q->front != q->rear)
    {
        data = dequeue(q);
        enqueue(&temp, data);
    }
    data = dequeue(q);
    while(temp.front != NULL)
    {
        data = dequeue(&temp);
        enqueue(q, data);
    }
    return data;
}

int main()
{
    // implement stack using queue
    Queue q;
    initQueue(&q);
    push(&q, 1);
    push(&q, 2);
    push(&q, 3);
    push(&q, 4);
    push(&q, 5);
    cout<<pop(&q)<<endl;
    cout<<pop(&q)<<endl;
    cout<<pop(&q)<<endl;
    cout<<pop(&q)<<endl;
    return 0;
}