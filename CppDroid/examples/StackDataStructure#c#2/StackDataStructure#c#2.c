/*
Summary: Stack is a particular kind of abstract data type or collection. Theonly operations on a stack are the addition of an entity, known as push and removal of an entity, known as pop.The relation between the push and pop operations is such that the stack is a Last-In-First-Out (LIFO) data structure.
*/

#include <conio.h>
#include <stdio.h>
#define max 4
void push();
void pop();
void display();
int menu();
int stack[max], top=0;

void main()
{
	int ch;
	clrscr();
	do{
		ch=menu();
		switch(ch)
		{
			case 1: push();
			break;
			case 2: pop();
			break;
			case 3: display();
			break;
			case 4: exit(1);
			default: printf("\nEnter a valid choice!!");
		}
	}while(1);
}

int menu()
{
	int ch;
	printf("\nStack");
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
	printf("\nEnter your Choice:");
	scanf("%d",&ch);
	return ch;
}

void push()
{
	if(top==max)
		printf("\nOverflow");
	else
	{
		int element;
		printf("\nEnter Element:");
		scanf("%d",&element);
		printf("\nElement(%d) has been pushed at %d", element, top);
		stack[top++]=element;
	}
}

void pop()
{
	if(top==-1)
		printf("\nUnderflow");
	else
	{
		top--;
		printf("\nELement has been popped out!");
	}
}

void display()
{
	if(top==0)
		printf("\nStack is Empty!!");
	else
	{
		int i;
		for(i=0;i<top;i++)
			printf("%d",stack[i]);
	}
}

/*
Input: Stack
1.Push
2.Pop
3.Display
4.Exit
Enter your Choice:1
Enter Element:32
Stack
1.Push
2.Pop
3.Display
4.Exit
Enter your Choice:2
Stack
1.Push
2.Pop
3.Display
4.Exit
Enter your Choice:3
*/