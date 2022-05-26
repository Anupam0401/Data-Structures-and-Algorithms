#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE * newNode();
void insertNode(NODE **head, int number);

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
    NODE *newn = newNode(); //create a new node
    NODE *temp = *head;
    newn->data = number;  //assign the number to the data of new node
    newn->next = NULL;
    if(*head == NULL) //if list is initially empty
    {
        *head = newn;
        return;
    }
    while (temp ->next != NULL) //traverse till the end of list
    {
        temp = temp ->next;
    }
    temp->next = newn; //add the new node at the end
    return;
}

int main()
{
    NODE *head = newNode();
    int n;
    cout<<"\nEnter the number of elements to be inserted in the list"<<endl;
    cin>>n;
    cout<<"Enter the elements of linked list in INCREASING ORDER:\n";
    int temp;
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        insertNode(&head , temp); //insert the node at the end of list
    }
    if(head==NULL) //empty list case
        cout<<"Median = 0\n";
    else
    {
        NODE *m = head;
        int c=0;
        while(c<n/2)
        {
            m = m->next;
            c++;
        }
        if(n%2==0) //even length  case
            cout<<"Median = "<<(m->data + m->next->data)/2.0<<endl;
        else //odd length case
            cout<<"Median = "<<m->next->data<<endl;
    }
    return 0;
}