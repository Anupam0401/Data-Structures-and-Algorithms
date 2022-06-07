/*
Summary: Gnome sort(stupid sort) is a sorting algorithm which is similar to insertion sort, except that moving an element to its proper place is accomplished by a series of swaps, as in bubble sort. It is conceptually simple, requiring no nested loops.
Complexity - O(n^2)
*/

#include <stdio.h>
void main()
{
	int i, temp, ar[10], n;
	printf("\nenter the elemts number u would like to enter:  ");
	scanf("%d", &n);
	printf("\nenter the elements to be sorted through gnome sort: \n");
	for (i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	i = 0;
	while (i < n)
	{
		if (i == 0 || ar[i - 1] <= ar[i])
			i++;
		else
		{
			temp = ar[i-1];
			ar[i - 1] = ar[i];
			ar[i] = temp;
			i = i - 1;
		}
	}
	for (i = 0;i < n;i++)
		printf("%d\t", ar[i]);
		printf("\n");
}


/*
Input: enter the elemts number u would like to enter:7
enter the elements to be sorted through gnome sort:
6
0
9
5
2
4
3
*/