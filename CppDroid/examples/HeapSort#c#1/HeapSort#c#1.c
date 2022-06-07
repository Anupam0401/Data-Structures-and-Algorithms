/*
Summary: The heapsort algorithm can be divided into two parts.
-Step 1: a heap is built out of the data.
-Step 2: a sorted array is created by repeatedly removing the largest element from the heap, and inserting it into the array.
The heap is reconstructed after each removal. Once all objects have been removed from the heap, we have a sorted array. The direction of the sorted elements can be varied by choosing a min-heap or max-heap in step one.
Complexity: O(n·log n) 
*/

#include <stdio.h>
void main()
{
	int heap[10], no, i, j, c, root, temp;
	clrscr();
	printf("\n Enter no of elements :");
	scanf("%d", &no);
	printf("\n Enter the nos : ");
	for (i = 0; i < no; i++)
		scanf("%d", &heap[i]);
	for (i = 1; i < no; i++)
	{
		c = i;
		do
		{
			root = (c - 1) / 2;             
                if (heap[root] < heap[c])   /* to create MAX heap array */
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	printf("Heap array : ");
	for (i = 0; i < no; i++)
		printf("%d\t ", heap[i]);
	for (j = no - 1; j >= 0; j--)
	{
		temp = heap[0];
            heap[0] = heap[j];    /* swap max element with rightmost leaf element */
		heap[j] = temp;
		root = 0;
		do 
		{
                c = 2 * root + 1;    /* left node of root element */
			if ((heap[c] < heap[c + 1]) && c < j-1)
				c++;
                if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < j);
	} 
	printf("\n The sorted array is : ");
	for (i = 0; i < no; i++)
		printf("\t %d", heap[i]);
	printf("\n Complexity : \n Best case = Avg case = Worst case = O(n logn) \n");
	getch();
}

/*
Input: Enter no of elements :7
Enter the nos : 6
5
3
1
8
7
2
*/