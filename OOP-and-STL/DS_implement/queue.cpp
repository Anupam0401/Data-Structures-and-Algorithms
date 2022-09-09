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

void init(queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue *q, int data)
{
    queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(queue *q)
{
    if (q->front == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    queueNode *temp = q->front;
    q->front = q->front->next;
    free(temp);
}

void print(queue *q)
{
    queueNode *temp = q->front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    queue q;
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    return 0;
}