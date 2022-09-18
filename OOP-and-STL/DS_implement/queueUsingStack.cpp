#include<iostream>
using namespace std;

// implment queue using stack

typedef struct Node
{
    int data;
    Node *next;
}Node;

typedef struct Stack
{
    Node *top;
}Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}

void push(Stack *s, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if(s->top == NULL)
    {
        s->top = newNode;
    }
    else
    {
        newNode->next = s->top;
        s->top = newNode;
    }
}

int pop(Stack *s)
{
    if(s->top == NULL)
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else
    {
        Node *temp = s->top;
        int data = temp->data;
        s->top = s->top->next;
        delete temp;
        return data;
    }
}

void enqueue(Stack *s, int data)
{
    push(s, data);
}

int dequeue(Stack *s)
{
    Stack temp;
    initStack(&temp);
    while(s->top != NULL)
    {
        push(&temp, pop(s));
    }
    int data = pop(&temp);
    while(temp.top != NULL)
    {
        push(s, pop(&temp));
    }
    return data;
}

int main()
{
    Stack s;
    initStack(&s);
    enqueue(&s, 1);
    enqueue(&s, 2);
    enqueue(&s, 3);
    enqueue(&s, 4);
    cout<<dequeue(&s)<<endl;
    cout<<dequeue(&s)<<endl;
    cout<<dequeue(&s)<<endl;
    cout<<dequeue(&s)<<endl;
    return 0;
}
