#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} stackNode;

typedef struct Stack
{
    stackNode *top;
    stackNode *bottom;
} stack;

void init(stack *&s)
{
    s->top = NULL;
    s->bottom = NULL;
}

void push(stack *&s, int n)
{
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    newNode->data = n;
    newNode->next = NULL;
    if (s->bottom == NULL)
    {
        s->top = newNode;
        s->bottom = newNode;
        return;
    }
    s->bottom->next = newNode;
    s->bottom = s->bottom->next;
    return;
}

void pop(stack *&s)
{
    if (s->top == NULL)
    {
        cout << "\nStack is empty!" << endl;
        return;
    }
    cout << "\nThe top of the stack is " << s->top->data << endl;
    stackNode *temp = s->top;
    s->top = s->top->next;
    cout << "Elements sucessfully popped from the stack!" << endl;
    free(temp);
}

void printStack(stack *s)
{
    stackNode *temp = s->top;
    cout << "\nThe elements in the stack from top to bottom are as follows" << endl;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    stack *s;
    init(s);
    int n;
    cout << "\nEnter the number of nodes to insert in the stack: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        push(s, temp);
    }
    printStack(s);
    pop(s);
    printStack(s);
    return 0;
}