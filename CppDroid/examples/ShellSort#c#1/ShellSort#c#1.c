/*
Summary: Shell Sort generalizes an exchanging sort, such as insertion or bubble sort, by starting the comparison and exchange of elements with elements that are far apart before finishing with neighboring elements. Starting with far apart elements can move some out-of-place elements into position faster than a simple nearest neighbor exchange.The idea is to arrange the list of elements so that, starting anywhere, considering every hth element gives a sorted list.
*/

#include  <stdio.h>
#define size 10
/* Function Prototype */
int shell_sort(int []);
void main()
{
	int arr[size], i;
	clrscr();
	printf("Enter 10 elements to be sorted:");
	for (i = 0;i < size;i++)
	{
		scanf("%d", &arr[i]);
	}
	shell_sort(arr);
	printf("The array after sorting is:");
	for (i = 0;i < size;i++)
	{
		printf("\n%d", arr[i]);
	}
	getch();
}



    /* Code to sort array using shell sort */

int shell_sort(int array[])
{
	int i = 0, j = 0, k = 0, mid = 0;
	for (k = size / 2;k > 0;k /= 2)
	{
		for (j = k;j < size;j++)
		{
			for (i = j - k;i >= 0;i -= k)
			{
				if (array[i + k] >= array[i])
				{
					break;
				}
				else
				{
					mid = array[i];
					array[i] = array[i + k];
					array[i + k] = mid;
				}
			}
		}
	}
	return 0;
}


/*
Input: Enter the elements to be sorted:57
67
48
93
42
84
95
*/