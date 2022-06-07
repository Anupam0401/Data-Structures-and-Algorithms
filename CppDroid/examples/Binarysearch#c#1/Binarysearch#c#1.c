/*
Summary: Binary search compares the search value with the value of the middle element of the array. If they match, then a matching element has been found and its position is returned. Otherwise, if the search value is less than the middle element's value, then the algorithm repeats its action on the sub-array to the left of the middle element or, if the search value is greater, on the sub-array to the right.
Complexity - O(log n)
*/

#include <stdio.h>
void main()
{
	int array[10];
	int i, j, num, temp, keynum;
	int low, mid, high;

	printf("Enter the value of num \n");
	scanf("%d", &num);

	printf("Enter the elements one by one \n");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &array[i]);
	}

        /*  Bubble sorting begins */
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < (num - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	printf("Sorted array is...\n");
	for (i = 0; i < num; i++)
	{
		printf("%d\n", array[i]);
	}

	printf("Enter the element to be searched \n");
	scanf("%d", &keynum);
	/*  Binary searching begins */
	low = 1;
	high = num;
	do
	{
		mid = (low + high) / 2;
		if (keynum < array[mid])
			high = mid - 1;
		else if (keynum > array[mid])
			low = mid + 1;
	} while (keynum != array[mid] && low <= high);
	if (keynum == array[mid])
	{
		printf("SEARCH SUCCESSFUL \n");
		printf("Number Located at position:%d ",mid+1);
	}
	else
	{
		printf("SEARCH FAILED! \n Number not found.");
	}
	getch();
}

/*
Input: Enter the value of num
5
Enter the elements one by one
23
90
56
15
58
Sorted array is...
15
23
56
58
90
Enter the element to be searched
58
*/