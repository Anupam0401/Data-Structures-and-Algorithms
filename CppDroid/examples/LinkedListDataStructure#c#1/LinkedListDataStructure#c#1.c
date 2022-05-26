/*
Summary: Linked list is an ordered set of data elements, each containing a link to its successor. This program is to create a linked list. After creating the linked list ,the length of linked list is calculated.
*/

#include <stdio.h>
#include <conio.h>

#define newnode (struct node*) malloc(sizeof(struct node))

struct node
{
	int data;
	struct node *next;
};

struct node *create_list();

void main()
{
	struct node *f;
	int len;
	f = NULL;
	clrscr();
	
	f = create_list();
	len = find_len(f);
	printf("\n length = %d",len);
} // main

struct node *create_list()
{
	struct node *f,*c,*p;
	int tdata;	
	f = NULL;
	printf("\n Enter data ( use 0 to exit ) : ");
	scanf("%d",&tdata);
	while( tdata != 0 )
	{
		c = newnode;
		if( c == NULL)
		{
			printf("\n Insuf. mem. ");
			exit(0);
		}
		c->data = tdata;
		c->next = NULL;
		if( f== NULL)
			f = c;
		else
			p->next = c;
			p = c;
			printf("\n Enter data ( use 0 to exit ) : ");
			scanf("%d",&tdata);
	} //while
	return(f);
} // create list

int find_len(struct node *f)
{
	int len=0;
	struct node *t;	
	if( f == NULL)
	return(0);
	t = f;	
	while( t != NULL )
	{
		len++;
		t = t->next;
	}
	return(len);
}

/*
Input: Enter data ( use 0 to exit ) : 5

 Enter data ( use 0 to exit ) : 15

 Enter data ( use 0 to exit ) : 65

 Enter data ( use 0 to exit ) : 2

 Enter data ( use 0 to exit ) : 657

 Enter data ( use 0 to exit ) : 3

 Enter data ( use 0 to exit ) : 0
*/