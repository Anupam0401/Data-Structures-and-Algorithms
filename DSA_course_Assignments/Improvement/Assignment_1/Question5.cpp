#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE * newNode();
void insertNode(NODE **head, int number);
NODE *merge(NODE **list1, NODE **list2);
void Bubblesort(NODE **head);
void printList(NODE *node);
//dyanamically creates a new node
NODE * newNode()
{
    NODE *p;//p is temporary pointer variable
    p=(NODE*) malloc (sizeof(NODE));
    p->next=NULL;
    return p;
}

//inserts node at the end of the list
void insertNode(NODE **head, int number)
{
    NODE *newn = newNode();  //new node created for storing the given data
    NODE *temp = *head; //temporary node to traverse
    newn->data = number;
    newn->next = NULL;
    if(*head == NULL) //empty list case
    {
        *head = newn; 
        return;
    }
    while (temp ->next != NULL) //traverse till the end of the list
    {
        temp = temp ->next;
    }
    temp->next = newn;
    return;
}
//Function to merge the lists
//Done by adding the list 2 to the end of list 1
NODE *merge(NODE **list1, NODE **list2)
{
    NODE *temp = *list1; //temporary node for traversing the list1
    while(temp != NULL)
    {
        if(list2 != NULL && temp->next== NULL) //if we reached the end of list1 and list 2 is not empty
        {
            temp->next = *list2; //merge list2 to list1
            break;
        }
        temp = temp->next;
    }
    return *list1;
}
//Bubble sort function for sorting the merged list
void Bubblesort(NODE **head) //O(nm)
{
    NODE* p = *head; //node for pointing to the current node in the list
    NODE* temp = *head; //temporary node for traversal
    while (p->next != NULL) {
        temp = p->next;
        while (temp != NULL) {
 
            if (temp->data < p->data) { //perform swap
                int t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
            temp = temp->next;
        }
        p = p->next;
    }
}
//Function for printing the list
void printList(NODE *node) //O(n)
{
    while(node != NULL)
    {
        cout<<node->data<<"  ";
        node = node->next;
    }
    cout<<"\n";
}

int main()
{
    int n1,n2;
    cout<<"Enter the number of elements in list 1"<<endl;
    cin>>n1;
    cout<<"Enter the list 1:  ";
    NODE *head1, *head2; //declaring the head nodes of the 2 lists
    head1 = NULL;
    int a = 0;
    for(int i=0; i<n1; i++)
    {
        cin>>a;
        insertNode(&head1, a);
    }
    cout<<"LIST 1:   ";
    printList(head1);
    head2 = NULL;
    cout<<"\n\nEnter the number of elements in list 2"<<endl;
    cin>>n2;
    int b;
    cout<<"Enter the list 2: ";
    for(int j=0; j<n2; j++)
    {
        cin>>b;
        insertNode(&head2, b);
    }
    cout<<"LIST 2:   ";
    printList(head2);
    head1 = merge(&head1 , &head2);
    cout<<"\nAfter merging both the lists:   ";
    printList(head1);
    Bubblesort(&head1);
    cout<<"\n\nThe final sorted list:   ";
    printList(head1);
    cout<<"\n";
    return 0;
}