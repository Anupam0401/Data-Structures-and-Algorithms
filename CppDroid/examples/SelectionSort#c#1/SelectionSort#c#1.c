/*
Summary: Selection sort divides the input list into two parts: the sublist of items already sorted and the sublist of items remaining to be sorted. It proceeds by finding the smallest (or largest) element in the unsorted sublist, exchanging it with the leftmost unsorted element and moving the sublist boundaries one element to the right.
Complexity - O(n^2)
*/

#include<conio.h>
#include<stdio.h>
#define max 50

void selsort(int, int[]);
void main()
{
	int i, size, data[max];
	clrscr();

	printf("\nEnter no of Elements:");
	scanf("%d",&size);

	printf("\nEnter Elements:");
	for(i=1;i<=size;i++)
		scanf("%d",&data[i]);

	printf("\nUnsorted data:\n");
	for(i=1;i<=size;i++)
		printf("%d\t",data[i]);

	selsort(size, data);
	getch();
}

void selsort(int n, int data[])
{
	int i, j, min, temp;
	printf("\nSorted List is:\n");
	for(i=1;i<=n-1;i++)
	{
		min = i;
		for(j=i+1;j<=n;j++)
		{
			if(data[j]<data[min])
				min = j;
		}	
		temp=data[i];
		data[i]=data[min];
		data[min]=temp;
	}
	for(i=1;i<=n;i++)
		printf("%d\t",data[i]);
}

/*
Input: Enter no of Elements:5
Enter Elements: 50
40
30
20
10
*/