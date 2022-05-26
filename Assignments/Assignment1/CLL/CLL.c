#include<stdio.h>
#include<stdlib.h>
struct node 
	{
		int data;
		struct node *link;
	};
void append(struct node **root,int x)
{
    if(*root==NULL)
    {
    	struct node *temp;
    	temp=(struct node *)malloc(sizeof(struct node));
    	temp->data=x;
    	*root=temp;
    	temp->link=*root;
    }
    else
    {
    	struct node *p;
    	p=*root;
    	while(p->link!=*root)
    		{p=p->link;}
    	struct node *temp;
    	temp=(struct node *)malloc(sizeof(struct node));
    	temp->data=x;
    	p->link=temp;
    	temp->link=*root;
    }
}
void InsertSorted(struct node **root,int x)
{
	if(*root==NULL)
		{printf("LIST IS EMPTY\n");}
	else
	{
         printf("%d INSERTED IN THE LIST:\n",x);
        struct node *p;
    	p=*root;
    	if(x<(p->data))
    	{
    		struct node *q;
            q=*root;
            while(q->link!=*root)
            {q=q->link;}
            struct node *temp;
    		temp=(struct node *)malloc(sizeof(struct node));
    		temp->data=x;
    		temp->link=*root;
    		*root=temp;
            q->link=*root;
    	}
    	else
    		{
    			struct node *p;
    			p=*root;
    			while(1)
    			{
    				if(p->link==*root)
    					{break;}
    				else if(x<=((p->link)->data))
    					{break;}
    				else
    					{p=p->link;}
    			}
    			struct node *temp;
    			temp=(struct node *)malloc(sizeof(struct node));
    			temp->data=x;
    			temp->link=p->link;
    			p->link=temp;

    		}
	}
}
void InsertSort(struct node ***root,int y)
{
    if(**root==NULL)
        {printf("LIST IS EMPTY\n");}
    else
    {
        struct node *p;
        p=**root;
        if(y<(p->data))
        {
            struct node *q;
            q=**root;
            while(q->link!=**root)
            {q=q->link;}
            struct node *temp;
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=y;
            temp->link=**root;
            **root=temp;
            q->link=**root;
        }
        else
            {
                struct node *p;
                p=**root;
                while(1)
                {
                    if(p->link==**root)
                        {break;}
                    else if(y<=((p->link)->data))
                        {break;}
                    else
                        {p=p->link;}
                }
                struct node *temp;
                temp=(struct node *)malloc(sizeof(struct node));
                temp->data=y;
                temp->link=p->link;
                p->link=temp;
            }
    }
}
void UpdateSorted(struct node **root,int x,int y)
{
    if(*root==NULL)
        {printf("LIST IF EMPTY\n");}
    else
    {
        struct node *p,*q;
        p=*root;
        q=p;
        if(p->data==x)
        {
            q=p;
        }
        else if(p->link!=*root)
        {
            q=p;
            p=p->link;
        }
        while(p->data!=x&&p!=*root)
        {
            if(p->link==*root)
                {break;}
            q=p;
            p=p->link;
        }
        if(p->link==*root&&p->data!=x)
            {printf("ELEMENT IS NOT PRESENT IN LIST\n\n");}
        else
            {
                printf("%d IS DELETED AND %d IS ADDED\n",x,y);
                struct node *r;
                r=*root;
                while(r->link!=*root)
                {r=r->link;}
                if(*root==p)
                {
                    struct node *temp;
                    temp=p;
                    *root=temp->link;
                    temp->link=NULL;
                    free(temp);
                    r->link=*root;
                }
                else
                {
                    struct node *temp;
                    temp=p;
                    if(p->link!=*root)
                    {q->link=(q->link)->link;}
                    else
                    {
                        q->link=*root;
                    }
                    temp->link=NULL;
                    free(temp);
                }
                InsertSort(&root,y);
            }
        
    }
}
void DisplayList(struct node **root)
{
	struct node *p;
    	p=*root;
        printf("%d  ",p->data);
        p=p->link;
    	while(p!=*root)
    	{
    		printf("%d  ",p->data);
    		p=p->link;
    	}
    	printf("\n");
}
int main()
{
	
    struct node *root=NULL;
    int t,x,i,I,J;
    printf("ENTER NO. OF ELEMENTS N:");
    scanf("%d",&t);
    printf("ENTER N SPACE SEPARATED ELEMENTS IN INCREASING ORDER ONLY:\n");
    while(t--)
    {
        scanf("%d",&x);
        append(&root,x);
    }
    printf("ENTER ELEMENT TO BE INSERTED:");
    scanf("%d",&i);
    InsertSorted(&root,i);
    printf("LIST IS:\n");
    DisplayList(&root);

    printf("\nENTER TWO SPACE SEPARATED ELEMENT TO BE DELETED AND INSERTED:\n");
    scanf("%d %d",&I,&J);
    UpdateSorted(&root,I,J);
    printf("LIST IS:\n");
    DisplayList(&root);
    
    return 0;
}