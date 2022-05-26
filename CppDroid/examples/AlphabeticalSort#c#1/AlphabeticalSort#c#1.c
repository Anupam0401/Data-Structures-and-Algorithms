/*
Summary: Alphabetical sort is a program whereby strings of characters are placed in order based on the position of the characters in the conventional ordering of an alphabet.
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
void main()
{
	char name[10][8], tname[10][8], temp[8];
	int i, j, n;
	printf("Enter the value of n \n");
	scanf("%d", &n);
	printf("Enter %d names ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", name[i]);
		strcpy(tname[i], name[i]);
	}
	for (i = 0; i < n - 1 ; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(name[i], name[j]) > 0)
			{
				strcpy(temp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], temp);
			}
		}
	}
	printf("\n----------------------------------------\n");
	printf("Input Names\tSorted names\n");
	printf("------------------------------------------\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\t\t%s\n", tname[i], name[i]);
	}
	printf("------------------------------------------\n");
	getch();
}

/*
Input: Enter the value of n
7
Enter 7 names
heap
stack
queue
object
class
program
project
*/