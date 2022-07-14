// PROGRAM TO IMPLEMENT insertSorted() and updateSorted() in CIRCULAR LINKED LIST
//Done by ANUPAM KUMAR,11940160

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *newNode() //creates a new node dynamically
{
    NODE *p; //p is temporary pointer variable
    p = (NODE *)malloc(sizeof(NODE));
    p->next = NULL;
    return p;
}
NODE *insertSorted(NODE *head, NODE *tail, int n)
{
    NODE *newv;
    newv = newNode();
    NODE *temp, *temp1;
    temp = head;
    while (n > temp->data)
    {
        temp1 = temp;
        if (temp->next == head)
        {
            break;
        }
        temp = temp->next;
    }
    if (n >= tail->data)
    {
        newv->data = n;
        newv->next = head;
        tail->next = newv;
        tail = newv;
    }
    else if (n <= head->data)
    {
        newv->data = n;
        newv->next = head;
        tail->next = newv;
        head = newv;
    }
    else
    {
        newv->data = n;
        newv->next = temp;
        temp1->next = newv;
    }
    return head;
}
NODE *delete (NODE *head, NODE *tail, int n)
{
    NODE *temp, *temp1; //temp1 and temp are temporary pointer variable.
    temp = head;
    while (n != temp->data)
    {
        temp1 = temp;
        temp = temp->next;
    }

    if (n == head->data) //deletion at the beginning
    {
        head = head->next;
        tail->next = head;
    }
    else if (tail->data == n) //deletion at the end
    {
        temp1->next = head;
        tail->next = NULL;
        tail = temp1;
    }
    else //deletion from somewhere in the middle
    {
        temp1->next = temp->next;
        temp->next = NULL;
    }
    return head;
}

NODE *updateSorted(NODE *head, NODE *tail, int old, int update)
{
    NODE *temp;
    head = delete (head, tail, old);
    head = insertSorted(head, tail, update);
    return head;
}
void print(NODE *head)
{
    NODE *temp;
    temp = head;
    printf("List : ");
    while (temp->next != head)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    int count, n, o;
    NODE *newv, *head, *tail, *temp;
    head = NULL;
    tail = NULL;
    printf("Enter the number of nodes \n");
    scanf("%d", &count);
    printf("\nEnter the elements of the list in ascending order\n");
    for (int i = 1; i <= count; i++)
    {
        newv = newNode();
        scanf("%d", &n);
        newv->data = n;
        newv->next = NULL;
        if (head == NULL)
        {
            head = newv;
            tail = newv;
        }
        else
        {
            tail->next = newv;
            tail = newv;
            tail->next = head;
        }
    }
    print(head);
    printf("Enter the number to be inserted in the list\n");
    scanf("%d", &n);
    head = insertSorted(head, tail, n);
    print(head);
    printf("Enter the number to be replaced and the updated number\n");
    scanf("%d%d", &o, &n);
    head = updateSorted(head, tail, o, n);
    print(head);
    return 0;
}
