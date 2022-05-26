/*
Summary: Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.
Two classifications of radix sorts are least significant digit (LSD) radix sorts and most significant digit (MSD) radix sorts. LSD radix sorts process the integer representations starting from the least digit and move towards the most significant digit. MSD radix sorts work the other way around.
Complexity - O(d·n) 
*/

#include <stdio.h>
int min = 0, count = 0, array[100] = {0}, array1[100] = {0};
void main()
{
	int k, i, j, temp, t, n;
	clrscr();
	printf("Enter size of array :");
	scanf("%d", &count);
	printf("Enter elements into array :");
	for (i = 0; i < count; i++)
	{
		scanf("%d", &array[i]);
		array1[i] = array[i];
	}
	for (k = 0; k < 3; k++)
	{    
		for (i = 0; i < count; i++)
		{
                min = array[i] % 10;        /* To find minimum lsd */
			t = i;
			for (j = i + 1; j < count; j++)    
			{
				if (min > (array[j] % 10))
				{
					min = array[j] % 10; 
					t = j;
				}
			}
			temp = array1[t];
			array1[t] = array1[i];
			array1[i] = temp;
			temp = array[t];
			array[t] = array[i];
			array[i] = temp;
		}
            for (j = 0; j < count; j++)        /*to find MSB */
		array[j] = array[j] / 10;
	}
	printf("Sorted Array (lSdradix sort) : ");
	for (i = 0; i < count; i++)
		printf("%d ", array1[i]);
	getch();    
}


/*
Input: Enter size of array :7
Enter elements into array :170    
45 
90
75
802
24
2
*/