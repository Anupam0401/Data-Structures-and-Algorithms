#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
typedef struct Node
{
    int data;
    struct Node* next;
}NODE;
 
// Helper function to print a given linked list
void printList(NODE* head)
{
    NODE* temp = head;
    while (temp!=NULL)
    {
        printf("%d —> ", temp->data);
        temp = temp->next;
    }
 
    printf("NULL\n");
}

// Helper function to insert a new node at the beginning of the linked list
void insert(NODE** head, int data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Function takes the node from the front of the source and moves it
// to the front of the destination
void moveNode(NODE** destRef, NODE** sourceRef)
{
    // if the source list empty, do nothing
    if (*sourceRef == NULL) {
        return;
    }
 
    NODE* newNode = *sourceRef;  // the front source node
    *sourceRef = (*sourceRef)->next;    // advance the source pointer
    newNode->next = *destRef;           // link the old dest off the new node
    *destRef = newNode;                 // move dest to point to the new node
}
 
// Takes two lists sorted in increasing order and merge their nodes
// to make one big sorted list, which is returned
NODE* sortedMerge(NODE* a, NODE* b)
{
    // a dummy first node to hang the result on
    NODE dummy;
    dummy.next = NULL;
 
    // points to the last result node — so `tail->next` is the place
    // to add new nodes to the result.
    NODE* tail = &dummy;
 
    while (1)
    {
        // if either list runs out, use the other list
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
 
        if (a->data <= b->data) {
            moveNode(&(tail->next), &a);
        }
        else {
            moveNode(&(tail->next), &b);
        }
 
        tail = tail->next;
    }
 
    return dummy.next;
}
 
int main()
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    NODE *a = NULL, *b = NULL;
    for (int i = n - 1; i >= 0; i = i - 2) {
        insert(&a, keys[i]);
    }
 
    for (int i = n - 2; i >= 0; i = i - 2) {
        insert(&b, keys[i]);
    }
 
    // print both lists
    printf("First List: ");
    printList(a);
 
    printf("Second List: ");
    printList(b);
 
    NODE* head = sortedMerge(a, b);
    printf("After Merge: ");
    printList(head);
 
    return 0;
}