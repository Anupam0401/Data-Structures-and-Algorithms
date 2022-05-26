/*
Summary: Linear search or sequential search is a method for finding a particular value in a list, that consists of checking every one of its elements, one at a time and in sequence, until the desired one is found.
Complexity - O(n)
*/

#include <stdio.h>
void main()
{  
	int array[10];
	int i, num, keynum, found = 0;

	printf("Enter the value of num \n");
	scanf("%d", &num);

	printf("Enter the elements one by one \n");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &array[i]);
	}

	printf("Enter the element to be searched \n");
	scanf("%d", &keynum);
	/*  Linear search begins */
	for (i = 0; i < num ; i++)
	{
		if (keynum == array[i] )
		{
			found = 1;
			break;
		}
	}
	if (found == 1){
		printf("Element is present in the array\n");
		printf("Number Located at position:%d ",i+1);
	}
	else
		printf("Element is not present in the array\n");

	getch();
}

/*
Input: Enter the value of num
5
Enter the elements one by one
456
78
90
40
100
Enter the element to be searched
40
*/