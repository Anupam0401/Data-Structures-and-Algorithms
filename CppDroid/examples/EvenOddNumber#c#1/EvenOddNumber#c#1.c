/*
Summary: Check whether a number entered by user is even or odd.
*/

#include <stdio.h> 
int main(){
	int num; 

	printf("Enter an integer you want to check: ");
	scanf("%d",&num);

	 /* Checking whether remainder is 0 or not. */
	if((num%2)==0) 
		printf("%d is even.",num); 
	else 
		printf("%d is odd.",num);
	return 0; 
} 

/*
Input: Enter an integer you want to check: 25
*/