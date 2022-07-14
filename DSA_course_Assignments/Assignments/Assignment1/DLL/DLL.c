#include<stdio.h>
#include<stdlib.h>
struct node 
	{
		int data;
		struct node *left;
		struct node *right;
	};
void append(struct node **root,int x)
{
    if(*root==NULL)
    {
    	struct node *temp;
    	temp=(struct node *)malloc(sizeof(struct node));
    	temp->data=x;
    	*root=temp;
    	temp->left=NULL;
    	temp->right=NULL;
    }
    else
    {
    	struct node *p;
    	p=*root;
    	while(p->right!=NULL)
    		{p=p->right;}
    	struct node *temp;
    	temp=(struct node *)malloc(sizeof(struct node));
    	temp->data=x;
    	p->right=temp;
    	temp->right=NULL;
    	temp->left=p;
    }
}
void InsertSorted(struct node **root,int x)
{
	if(*root==NULL)
		{printf("LIST IS EMPTY\n");}
	else
	{
        printf("%d IS INSERTED IN THE LIST:\n",x);
        struct node *p;
    	p=*root;
    	if(x<(p->data))
    	{
    		struct node *temp;
    		temp=(struct node *)malloc(sizeof(struct node));
    		temp->data=x;
    		temp->right=*root;
    		temp->left=NULL;
    		(*root)->left=temp;
    		*root=temp;
    	}
    	else
    		{
    			struct node *p;
    			p=*root;
    			while(1)
    			{
    				if(p->right==NULL)
    					{break;}
    				else if(x<=((p->right)->data))
    					{break;}
    				else
    					{p=p->right;}
    			}
    			struct node *temp;
    			temp=(struct node *)malloc(sizeof(struct node));
    			temp->data=x;
    			temp->right=p->right;
    			temp->left=p;
    			if(p->right!=NULL)
    			{
    				(p->right)->left=temp;
    			}
    			p->right=temp;
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
            struct node *temp;
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=y;
            temp->right=**root;
            temp->left=NULL;
            (**root)->left=temp;
            **root=temp;
        }
        else
            {
                struct node *p;
                p=**root;
                while(1)
                {
                    if(p->right==NULL)
                        {break;}
                    else if(y<=((p->right)->data))
                        {break;}
                    else
                        {p=p->right;}
                }
                struct node *temp;
                temp=(struct node *)malloc(sizeof(struct node));
                temp->data=y;
                temp->right=p->right;
                temp->left=p;
                if(p->right!=NULL)
                {
                    (p->right)->left=temp;
                }
                p->right=temp;
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
        while(p->data!=x&&p!=NULL)
        {
            if(p->right==NULL)
                {break;}
            q=p;
            p=p->right;
        }
        if(p->right==NULL&&p->data!=x)
            {printf("ELEMENT IS NOT PRESENT IN LIST\n\n");}
        else
            {
                printf("%d IS DELETED AND %d IS ADDED\n",x,y);
                if(*root==p)
                {
                    struct node *temp;
                    temp=p;
                    *root=temp->right;
                    temp->right=NULL;
                    free(temp);
                }
                else
                {
                    struct node *temp;
                    temp=p;
                    if(p->right!=NULL)
                    {((q->right)->right)->left=q;}
                    q->right=(q->right)->right;
                    temp->right=NULL;
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
    	while(p!=NULL)
    	{
    		printf("%d  ",p->data);
    		p=p->right;
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
    
    printf("\nENTER TWO SPACE SEPARATED ELEMENT TO BE DELETED AND INSERTED\n:");
    scanf("%d %d",&I,&J);
	UpdateSorted(&root,I,J);
    printf("LIST IS:\n");
    DisplayList(&root);
    return 0;
}






