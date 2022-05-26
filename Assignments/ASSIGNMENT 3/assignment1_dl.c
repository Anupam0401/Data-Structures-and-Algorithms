#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
    }NODE;

    NODE * newNode()
    {
        NODE *p;
        p=(NODE*) malloc (sizeof(NODE));
        p->prev=NULL;
        p->next=NULL;
        return p;
        }
     int isEmpty(NODE * list)
     {
        return (list==NULL);
     }

     void append(NODE *list,int n)
     {
        NODE *p,*tail;
        tail= newNode();
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

  /*   NODE *prepend(NODE *list,int n)
     {
        NODE *p,*tail;
        p=newNode();
        tail=list;
        p->data=n;
        p->next=tail->prev;
        p->prev=NULL;
        return p;
     }*/

      void delete(NODE *list,int n)
      {
        NODE *p,*tail,*r;
        p=list;
        while(n!=p->data)
        {

            if(p->next==NULL)
            {
                printf("Invalid number\n");
                return;
            }
            p=p->next;
        }
        if(p->data==n&&p->prev!=NULL&&p->next!=NULL)
        {
            p->next->prev=p->prev;
            p->prev->next=p->next;
            p->next=NULL;
            p->prev=NULL;
        }
        else if(p->next!=NULL)
        {
            p->next->prev=NULL;
            p=p->next;

        }
        else
        {
            p->prev->next=NULL;
            p->prev=NULL;
        }

      }

      NODE *insertSorted(NODE *list,int n)
      {
          NODE *p,*tail;
          p=list;
          while(n>p->data&&p->next!=NULL)
          {
              p=p->next;
          }
          p=p->prev;
          tail=newNode();
          if(p->prev==NULL)
          {
              tail->data=n;
              tail->prev=NULL;
              tail->next=p;
              p->prev=tail;
          }
          else if(p->next==NULL)
          {
              tail->next=NULL;
              tail->data=n;
              tail->prev=p;
              p->next=tail;
          }
          else
          {
              tail->data=n;
              tail->next=p->next;
              tail->prev=p;
              p->next=tail;
          }
          return list;
      }


      NODE *updateSorted(NODE *list,int old,int new)
      {
          NODE *tail;
          delete(list,old);
          tail=insertSorted(list,new);
          return list;
      }
      void print(NODE *list)
      {
          NODE *temp=list;
           while(temp->next!=NULL)
           {
               printf("%d  ",temp->data);
               temp=temp->next;
           }
      }

      int main()
      {
          int count,n,o;
          printf("\nHow many numbers do you want to enter ?\n");
          scanf("%d",&count);
          NODE *p,*tail;
          p=newNode();
          tail=p;
          printf("\n Enter the numbers in ascending order\n");
          scanf("%d",&tail->data);
          for(int i=1;i<=(count-1);i++)
          {
             scanf("%d",&n);
             append(tail,n);
             tail=tail->next;

          }
          printf("\n Enter a number to insert in the list\n");
          scanf("%d",&n);
          p=insertSorted(p,n);
          print(p);
          printf("\n Enter a number to replace and the other number to be updated in the list \n");
          scanf("%d%d",&o,&n);
          p=updateSorted(p,o,n);
          print(p);
          return 0;
        }
