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
        return p;
        }
     int isEmpty(NODE * list)
     {
        return (list==NULL);
     }

     NODE *append(NODE *list,int n)
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
        }
        return p;
     }

     NODE *prepend(NODE *list,int n)
     {
        NODE *p,*tail;
        p=newNode();
        tail=list;
        p->data=n;
        p->next=tail->prev;
        p->prev=NULL;
        return p;
     }

      void delete(NODE *list,int n)
      {
        NODE *p,*tail,*r;
        p=list;
        while(n!=p->data)
        {

            if(p->next==NULL)
            {
                printf("INvalid number\n");
                return;
            }
            p=p->next;
        }
        if(p->data==n&&p->prev!=NULL&&p->next!=NULL)
        {
            p->next->prev=p->prev;
            p->prev->next=p->next;
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
          NODE *p,*tail,*r;
          p=list;
          while(n>p->data&&p->next!=NULL)
          {
              p=p->next;
          }
          r=p->prev;
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
              tail->prev=p->prev;
              p->next=tail;
          }
          else
          {
              tail->data=n;
              tail->next=p;
              tail->prev=p->prev;
              p->prev=tail;
              r->next=tail->prev;

          }
          return p;
      }


      NODE *updateSorted(NODE *list,int old,int new)
      {
          NODE *p,*tail;
          p=list;
          delete(list,old);
          tail=insertSorted(list,new);
          return tail;
      }
      void print(NODE *list)
      {
           while(list->next!=NULL)
           {
               printf("%d",list->data);
               list=list->next;
           }
      }

      int main()
      {
          int count,n,o;
          printf("\nHow many numbers do you want to enter ?\n");
          scanf("%d",&count);
          NODE *p,*tail;
          p=newNode();
          p->prev=NULL;
          p->next=NULL;
          tail=p;
          printf("\n Enter the numbers in ascending order\n");
          scanf("%d",&tail->data);
          for(int i=1;i<=(count-1);i++)
          {
             scanf("%d",&n);
             tail->next=append(tail,n);
             tail=tail->next;
             printf(".");

          }

          printf("\n Enter a number\n");
          scanf("%d",&n);
          p=insertSorted(p,n);
          print(p);
          printf("\n Enter a number to replace and the other number\n");
          scanf("%d%d",&o,&n);
          p=updateSorted(p,o,n);
          print(p);
          return 0;
        }
