// PROGRAM TO IMPLEMENT insertSorted() and updateSorted() in DOUBLE LINKED LIST
//Done by ANUPAM KUMAR,11940160

#include<stdio.h>//header
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
    }NODE;

    NODE * newNode()//creates a new node dynamically
    {
        NODE *temp;//temporary pointer variable
        temp=(NODE*) malloc (sizeof(NODE));
        temp->prev=NULL;
        temp->next=NULL;
        return temp;
        }
     int isEmpty(NODE * list)
     {
        return (list==NULL);
     }

     void append(NODE *list,int n)
     {
        NODE *p,*tail;//p  is a temporary pointer variable
        tail= newNode();//a node to be inserted at the end of the list
        p=list;
        if(isEmpty(list))
        {
            p->data=n;
            p->next=NULL;
            p->prev=NULL;
        }
        else
        {

            while(p->next!=NULL){
                    p=p->next;

            }
            tail->data=n;
            tail->next=NULL;
            tail->prev=p;
            p->next=tail;
        }

     }

      NODE *delete(NODE *head,int n)
      {
        NODE *p;// p is a temporary pointer variable
        p=head;// p is initially pointing to the head node
        while(n!=p->data)
        {
            p=p->next;
        }
        if(n==head->data)//for deleting the node at the beginning
        {
            p=p->next;
            p->prev->next=NULL;
            p->prev=NULL;
            head=p;
        }
        else if(p->next==NULL)//for deleting the node at the end
        {
            p->prev->next=NULL;
            p->prev=NULL;
        }
        else//for deleting the node somewhere in the middle of the list
        {
            p->prev->next=p->next;
            p->next->prev=p->prev;
            p->prev=NULL;
            p->next=NULL;
        }

        return head;

      }

      NODE *insertSorted(NODE *head,int n)
      {
          NODE *p,*newnode;
          p=head;

          while(n>p->data&&p->next!=NULL)
          {

              p=p->next;
          }
          newnode=newNode();
          if(p->prev==NULL)//insertion at the beginning
          {
              newnode->data=n;
              newnode->prev=NULL;
              newnode->next=p;
              p->prev=newnode;
              head=newnode;
          }
          else if(n>p->data)//insertion at the end
          {
              newnode->next=NULL;
              newnode->data=n;
              newnode->prev=p;
              p->next=newnode;
          }
          else//insertion somewhere in the middle
          {
              newnode->data=n;
              newnode->next=p;
              newnode->prev=p->prev;
              p->prev->next=newnode;
              p->prev=newnode;
          }
          return head;
      }


      NODE *updateSorted(NODE *head,int old,int new)
      {
          NODE *tail;
          head=delete(head,old);//deletion of old node
          tail=insertSorted(head,new);//addition of new node
          return head;
      }
      void print(NODE *list)
      {
          NODE *temp=list;
          printf("\nlist :");
           while(temp->next!=NULL)
           {
               printf("%d  ",temp->data);
               temp=temp->next;
           }
           printf("%d  \n",temp->data);
      }

      int main()
      {
          int count,n,o;
          printf("How many numbers do you want to enter ?\n");
          scanf("%d",&count);
          NODE *p,*tail,*head;
          p=newNode();
          tail=p;
          printf("\nEnter the numbers in ascending order\n");
          scanf("%d",&tail->data);
          head=tail;
          for(int i=1;i<=(count-1);i++)
          {
             scanf("%d",&n);
             append(tail,n);
             tail=tail->next;

          }
          print(head);
          printf("\n Enter a number to insert in the list\n");
          scanf("%d",&n);
          head=insertSorted(head,n);
          print(head);
          printf("\n Enter a number to replace and the other number to be updated in the list \n");
          scanf("%d%d",&o,&n);
          head=updateSorted(head,o,n);
          print(head);
          return 0;
        }