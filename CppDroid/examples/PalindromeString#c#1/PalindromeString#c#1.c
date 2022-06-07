/*
Summary: Palindromes are words or phrases that read the same in both directions.
*/

#include<stdio.h>
#include<string.h>
#include<conio.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main()
{
	char a[100], b[100];
	
	//Get the number from user.
	printf("Enter the string to check if it is a palindrome\n");
	gets(a);

	//copy input to another array b
	strcpy(b,a);

	//Reverse it.
	strrev(b);

	/*Compare it with the number entered by the user.If both are same then print palindrome number*/
	if( strcmp(a,b) == 0 )
		printf("\nEntered string is a palindrome.\n");
	else
		printf("\nEntered string is not a palindrome.\n");
	getch();
	return 0;
}

/*
Input: radar
*/