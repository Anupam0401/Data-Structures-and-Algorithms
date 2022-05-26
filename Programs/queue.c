#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 4

typedef struct words
{
	char *word[MAX];
	int f_index;
	int r_index;
	int num_elements;
}queue;


queue *create();
void enqueuer(queue *q,char data[]);
void dequeue(queue *q);
void display(queue *q);
int isFull(queue *q);
int isEmpty(queue *q);


int main()
{
	queue *list;
	list = create(list);
	char temp[10];
	// printf("Enter your option :\n");
	// strcpy(temp,"anubhav");
	enqueuer(list,"anubhav");
	// strcpy(temp,"ujjwal");
	//enqueuer(list,"ujjwal");
	//enqueuer(list,"anubh");
	//enqueuer(list,"anub");
	printf("Select the numbers to the corresponding operations to perform.\n");
	printf("--------------------------------------------------------------\n");
	printf("\tOPERATIONS\tNUMBER CODE\n");
	printf("\t----------\t-----------\n");
	printf("\t  Add    :\t     1     \n");
	printf("\t  Delete :\t     2     \n");
	printf("\t  Print  :\t     3     \n");
	printf("\t  Quit   :\t     4     \n");

	while(1)
	{
		int num;
		scanf("%d",&num);

		switch(num)
		{
			case 1:
				scanf("%s",temp);
				/*char data[10];
				strcpy(data,temp);*/
				enqueuer(list,temp);
				display(list);
				break;

			case 2:
				dequeue(list);
				break;

			case 3:
				display(list);
				break;

			case 4:
				exit(1);
				break;

			default :
				printf("Command not recognized	.\n");
				break;

		}
	}

	return 0;
}


queue *create()
{
	queue *q = (queue *)malloc(sizeof(queue));
	if(q == NULL)
	{
		printf("Failed to create the queue.\n");
		exit(-1);
	}

	q -> f_index = 0;
	q -> r_index = 0;
	q -> num_elements = 0;

	return q;
}


void enqueuer(queue *q,char data[])
{
	if((q -> r_index) == MAX)
	{
		printf("Cannot add %s. Queue full.\n",data);
		return;
	}

	(q -> word[q -> r_index]) = data;
	printf("%s\n\n",data);
	(q -> r_index)++;
	++(q -> num_elements);
	return;
}


void dequeue(queue *q)
{
	if((q -> r_index) == (q -> f_index))
	{
		printf("The queue is empty. Nothing to delete.\n");
		return;
	}

	printf("%s\n",(q -> word[q -> f_index]));
	for(int i=(q -> f_index); i<(q -> r_index); i++)
	{
		q -> word[i] = q -> word[i+1];
	}
	--(q -> num_elements);
	--(q -> r_index);
	return;
}


int isEmpty(queue *q)
{
	return ((q -> r_index == q -> f_index) ? 1 : 0);
}


int isFull(queue *q)
{
	return ((q -> r_index == MAX) ? 1 : 0);
}


void display(queue *q)
{
	if(q -> f_index == q -> r_index)
	{
		printf("Queue empty. Nothing to display.\n");
		return;
	}

	for(int i = q ->f_index; i< q -> r_index; i++)
	{
		printf("%s  ",q -> word[i]);
	}
	printf("\n");
}
